#!/usr/bin/env python2
# Copyright (c) 2014 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

# Exercise the getchainttest API.  We introduce a network split, work
# on chains of different lengths, and join the network together again.
# This gives us two ttest, verify that it works.

from test_framework import BitcoinTestFramework
from util import assert_equal

class GetChainTtestTest (BitcoinTestFramework):

    def run_test (self):
        BitcoinTestFramework.run_test (self)

        ttest = self.nodes[0].getchainttest ()
        assert_equal (len (ttest), 1)
        assert_equal (ttest[0]['branchlen'], 0)
        assert_equal (ttest[0]['height'], 200)
        assert_equal (ttest[0]['status'], 'active')

        # Split the network and build two chains of different lengths.
        self.split_network ()
        self.nodes[0].setgenerate (True, 10);
        self.nodes[2].setgenerate (True, 20);
        self.sync_all ()

        ttest = self.nodes[1].getchainttest ()
        assert_equal (len (ttest), 1)
        shortTip = ttest[0]
        assert_equal (shortTip['branchlen'], 0)
        assert_equal (shortTip['height'], 210)
        assert_equal (ttest[0]['status'], 'active')

        ttest = self.nodes[3].getchainttest ()
        assert_equal (len (ttest), 1)
        longTip = ttest[0]
        assert_equal (longTip['branchlen'], 0)
        assert_equal (longTip['height'], 220)
        assert_equal (ttest[0]['status'], 'active')

        # Join the network halves and check that we now have two ttest
        # (at least at the nodes that previously had the short chain).
        self.join_network ()

        ttest = self.nodes[0].getchainttest ()
        assert_equal (len (ttest), 2)
        assert_equal (ttest[0], longTip)

        assert_equal (ttest[1]['branchlen'], 10)
        assert_equal (ttest[1]['status'], 'valid-fork')
        ttest[1]['branchlen'] = 0
        ttest[1]['status'] = 'active'
        assert_equal (ttest[1], shortTip)

if __name__ == '__main__':
    GetChainTtestTest ().main ()

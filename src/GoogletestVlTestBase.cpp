/*
 * GoogletestVlTestBase.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#include "GoogletestVlTestBase.h"

GoogletestVlTestBase::GoogletestVlTestBase() {
	m_top = 0;
	m_tfp = 0;
	m_init = false;
	m_timestamp = 0;
	m_steplist_idx = 0;
	m_steplist_sz = 0;
}

GoogletestVlTestBase::~GoogletestVlTestBase() {
	// TODO Auto-generated destructor stub
}

void GoogletestVlTestBase::SetUp() {
	m_clocks.clear();
	m_timestamp = 0;
	m_init = false;

	::testing::UnitTest *test = ::testing::UnitTest::GetInstance();
	fprintf(stdout, "testcases to run: %d\n", test->test_to_run_count());
	fprintf(stdout, " current testcase: %s::%s\n",
			test->current_test_case()->name(),
			test->current_test_info()->name());
}

void GoogletestVlTestBase::run() {
	if (!m_init) {
		m_steplist.push_back(ClockStep(
				m_clocks.at(0).first, 1, m_clocks.at(0).second/2));
		m_steplist.push_back(ClockStep(
				m_clocks.at(0).first, 0, m_clocks.at(0).second/2));
		m_steplist_idx = 0;
		m_steplist_sz = m_steplist.size();
		m_init = true;
	}

	for (int i=0; i<10000; i++) {
		const ClockStep &s = m_steplist.at(m_steplist_idx);
		*s.clock = s.clock_val;
		eval();
		if (m_tfp) {
			m_tfp->dump(m_timestamp);
		}

		m_timestamp += s.time_incr;

		m_steplist_idx = ((m_steplist_idx + 1) % m_steplist_sz);
	}

}

void GoogletestVlTestBase::TearDown() {
	delete m_top;
	m_top = 0;

	if (m_tfp) {
		m_tfp->close();
		m_tfp = 0;
	}
}

void GoogletestVlTestBase::addClock(CData *clk, double period) {
	m_clocks.push_back(std::pair<CData *, uint64_t>(clk, period));
}


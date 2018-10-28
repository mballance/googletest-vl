/*
 * GoogletestVlTestListener.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#include "GoogletestVlTestListener.h"
#include <stdio.h>

GoogletestVlTestListener::GoogletestVlTestListener() {
	m_num_tests = 0;
	m_num_failed = 0;
}

GoogletestVlTestListener::~GoogletestVlTestListener() {
	// TODO Auto-generated destructor stub
}

void GoogletestVlTestListener::OnTestStart(const ::testing::TestInfo &test_info) {
	// NOP
	fprintf(stdout, "OnTestStart\n");
	m_num_tests++;
}

void GoogletestVlTestListener::OnTestPartResult(const ::testing::TestPartResult &result) {
	fprintf(stdout, "OnTestPartResult\n");
	if (result.failed()) {
		m_num_failed++;
	}
}

void GoogletestVlTestListener::OnTestEnd(const ::testing::TestInfo &test_info) {
	// NOP
	fprintf(stdout, "OnTestEnd\n");
}



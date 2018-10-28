/*
 * GoogletestVlTestListener.h
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#ifndef PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTLISTENER_H_
#define PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTLISTENER_H_
#include <stdint.h>
#include "gtest/gtest.h"

class GoogletestVlTestListener : public ::testing::EmptyTestEventListener {
public:
	GoogletestVlTestListener();

	virtual ~GoogletestVlTestListener();

    virtual void OnTestStart(const ::testing::TestInfo &test_info);

    virtual void OnTestPartResult(const ::testing::TestPartResult &result);

    virtual void OnTestEnd(const ::testing::TestInfo &test_info);

    uint32_t num_tests() const { return m_num_tests; }

    uint32_t num_passed() const { return (m_num_tests - m_num_failed); }

    uint32_t num_failed() const { return m_num_failed; }


private:
    uint32_t				m_num_tests;
    uint32_t				m_num_failed;


};

#endif /* PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTLISTENER_H_ */

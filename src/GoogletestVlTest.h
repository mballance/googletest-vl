/*
 * GoogletestVlTest.h
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#ifndef SRC_GOOGLETESTVLTEST_H_
#define SRC_GOOGLETESTVLTEST_H_
#include "GoogletestVlTestBase.h"
#include "gtest/gtest.h"
#include <stdint.h>
#include <vector>

template <class T> class GoogletestVlTest : public GoogletestVlTestBase {
public:
	typedef GoogletestVlTest<T> BaseT;
public:
	GoogletestVlTest() { }

	virtual ~GoogletestVlTest() { };

	virtual void SetUp();

	T *top() const { return static_cast<T *>(m_top); }

protected:
	virtual void eval() const { static_cast<T *>(m_top)->eval(); }

};

template <class T> void GoogletestVlTest<T>::SetUp() {
	::testing::UnitTest *test = ::testing::UnitTest::GetInstance();
	GoogletestVlTestBase::SetUp();
	m_top = new T();

	m_tfp = new VerilatedLxt2C();
	top()->trace(m_tfp, 99);
	if (test->test_to_run_count() > 1) {
		char tmp[256];
		// Construct a unique name
		sprintf(tmp, "simx_%s::%s.lxt",
				test->current_test_case()->name(),
				test->current_test_info()->name());
		m_tfp->open(tmp);
	} else {
		// Just use a simple name
		m_tfp->open("simx.lxt");
	}
}

#endif /* SRC_GOOGLETESTVLTEST_H_ */

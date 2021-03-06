/*
 * GoogletestVlTestBase.h
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#ifndef PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTBASE_H_
#define PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTBASE_H_
#include "gtest/gtest.h"
#include "verilated.h"
#include "verilated_lxt2_c.h"
#include <vector>
#include <stdint.h>
#include <map>

class GoogletestVlTestBase : public ::testing::Test {
public:
	GoogletestVlTestBase();

	virtual ~GoogletestVlTestBase();

	virtual void SetUp();

	// Run for a maximum of <timeout>
	virtual void run(uint64_t cycles=1000000);

	virtual void TearDown();

	void addClock(CData *clk, double period);

	void addClock(CData &clk, double period);

	std::string testname() const;

	void raiseObjection(void *obj);

	void dropObjection(void *obj);

protected:

	virtual void eval() const = 0;

	struct ClockStep {
		CData			*clock;
		uint8_t			clock_val;
		double			time_incr;

		ClockStep(CData *clock, uint8_t clock_val, double time_incr) {
			this->clock     = clock;
			this->clock_val = clock_val;
			this->time_incr = time_incr;
		}
	};

protected:
	VerilatedModule									*m_top;
	VerilatedLxt2C 									*m_tfp;
	bool											m_init;
	std::vector<std::pair<CData *, double>>			m_clocks;
	std::vector<ClockStep>							m_steplist;
	uint32_t										m_steplist_idx;
	uint32_t										m_steplist_sz;
	double											m_timestamp;
	std::map<void *, uint32_t>						m_objections;
};

#endif /* PACKAGES_GOOGLETEST_VL_SRC_GOOGLETESTVLTESTBASE_H_ */

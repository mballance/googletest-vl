/*
 * GoogletestVlCmdlineProcessor.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: ballance
 */

#include <stdio.h>
#include "GoogletestVlCmdlineProcessor.h"

GoogletestVlCmdlineProcessor::GoogletestVlCmdlineProcessor(int argc, char **argv) {
	for (int i=0; i<argc; i++) {
		if (argv[i][0] == '+') {
			m_plusargs.push_back(argv[i]);
		}
		m_args.push_back(argv[i]);
	}
}

GoogletestVlCmdlineProcessor::~GoogletestVlCmdlineProcessor() {
	// TODO Auto-generated destructor stub
}

void GoogletestVlCmdlineProcessor::init(int argc, char **argv) {
	m_instance = new GoogletestVlCmdlineProcessor(argc, argv);
}

const GoogletestVlCmdlineProcessor &GoogletestVlCmdlineProcessor::instance() {
	if (!m_instance) {
		fprintf(stdout, "Error: calling GoogletestVlCmdlineProcessor::instance() before initialization\n");
	}

	return *m_instance;
}

bool GoogletestVlCmdlineProcessor::get_plusarg_values(const std::string &plusarg, std::vector<std::string> &values) const {
	bool ret = false;
	for (std::vector<std::string>::const_iterator it=m_plusargs.begin();
			it!=m_plusargs.end(); it++) {
		int i=0;

		while (i<plusarg.size() && i<it->size() && plusarg.at(i) == it->at(i)) {
			i++;
		}
		if (i == plusarg.size() && it->at(i) == '=') {
			fprintf(stdout, "plusarg %s matches pattern %s\n", it->c_str(), plusarg.c_str());
		}
		values.push_back(it->substr(i+1));
		ret = true;
	}

	return ret;
}

bool GoogletestVlCmdlineProcessor::get_plusarg_value(const std::string &plusarg, std::string &value) const {
	std::vector<std::string> values;
	get_plusarg_values(plusarg, values);

	if (values.size() > 0) {
		value = values.at(0);
	}

	return values.size() > 0;
}


GoogletestVlCmdlineProcessor *GoogletestVlCmdlineProcessor::m_instance = 0;

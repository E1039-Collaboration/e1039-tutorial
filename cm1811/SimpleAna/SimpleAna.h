/*
 * SimpleAna.h
 *
 *  Created on: Oct 29, 2017
 *      Author: yuhw@nmsu.edu
 */

#ifndef _H_SimpleAna_H_
#define _H_SimpleAna_H_

// Fun4All includes
#include <fun4all/SubsysReco.h>

// STL includes
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>

class PHG4TruthInfoContainer;
class PHG4HitContainer;

class TFile;
class TTree;

class TClonesArray;

class SimpleAna: public SubsysReco {

public:

	SimpleAna(const std::string &name = "SimpleAna", const std::string &out = "eval.root");
	virtual ~SimpleAna() {
	}

	int Init(PHCompositeNode *topNode);
	int InitRun(PHCompositeNode *topNode);
	int process_event(PHCompositeNode *topNode);
	int End(PHCompositeNode *topNode);

	int InitEvalTree();
	int ResetEvalVars();

private:

	int GetNodes(PHCompositeNode *topNode);

	int _event;


	//! Input nodes
	PHG4TruthInfoContainer *_g4truth_container;
	PHG4HitContainer *_g4hit_sensor;

	//! output TFile
	std::string _out_name;
	TTree *_tout;
	double _gmass;
	int _acc;
};


#endif /* _H_SimpleAna_H_ */

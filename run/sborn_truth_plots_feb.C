//#include "../../include/vect4.h"
//#include "../../src/vect4.cpp"
#include "../src/DecayEvt.C"
#include "TH1F.h"
#include "TDirectory.h"
#include <string>
#include <iostream>
//#include "AnalysisFunctions.C"

#define TREES 1000

//SEE LN 10_3_2019
void AnalyzeVertices(int dec_pdg){
	int pdg_par;
	int pdg_child_i;
	int pdg_child_ii;
	float mass_par;
	float mass_child_i;
	float mass_child_ii;
	float rlow, rhigh;
	if(dec_pdg == 310){
		pdg_par = 310;
		pdg_child_i = 211;
		pdg_child_ii = -211;
		mass_par = 0.497648;
		mass_child_i = 0.13957;
		mass_child_ii = mass_child_i;
		rlow = 0.2;
		rhigh = 0.6;
	}
	if(dec_pdg == 3122){
		pdg_par = 3122;
		pdg_child_i = 2212;
		pdg_child_ii = -211;
		mass_par = 1.115683;
		mass_child_i = 0.938272;
		mass_child_ii = 0.13957;
		rlow = 1;
		rhigh = 1.4;
	}
	//Return block
	TH1F INV_MASS("inv_mass","Invariant Mass Assuming Pions - All Tracks, All Vertices",1000,rlow,rhigh);//(0.35 - 0.65 for later cuts maybe)
	INV_MASS.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH2F NU_INT_YZ("nu_int_yz", "Neutrino Interaction Locations - YZ Plane", 50, -500, 500, 50, -500, 500);
	NU_INT_YZ.GetXaxis()->SetTitle("[cm]");
	TH2F DECAY_YZ("decay_yz", Form("%i Decay Locations - YZ Plane",dec_pdg), 50, -500, 500, 50, -500, 500);
	DECAY_YZ.GetXaxis()->SetTitle("[cm]");
	TH1F DECAY_LENGTH("decay_length", Form("%i Decay Length",dec_pdg), 50, 0, 100);
	DECAY_LENGTH.GetXaxis()->SetTitle("[cm]");
	TH1F P_DECAY("p_decay", Form("%i Starting Momentum",dec_pdg), 50, 0, 10);
	P_DECAY.GetXaxis()->SetTitle("momentum [GeV/c]");
	TH1F P_FRAME("p_frame", Form("%i Decay Frame Child Momentum",dec_pdg), 50, 0, 10);
	P_FRAME.GetXaxis()->SetTitle("momentum [GeV/c]");
	TH1F PT_RATIO("pt_ratio",Form("(%i) PT Ratio",pdg_par),500,0,1.2);//(0.48 - 0.52 for kaons)
	PT_RATIO.GetXaxis()->SetTitle("[unitless]");
	TH1F FRAME_BETA("frame_beta",Form("(%i) Frame Beta",pdg_par),500,0,1);//(0.48 - 0.52 for kaons)
	FRAME_BETA.GetXaxis()->SetTitle("[unitless]");
	
	//Armenteros Podolanski trial
	TH2F ARM_POD("arm_pod", Form("%i Armenteros-Podolanski Plot",dec_pdg), 150, -1, 1, 150, 0, 0.25);
	ARM_POD.GetYaxis()->SetTitle("p_{T} [GeV/c]");
	ARM_POD.GetXaxis()->SetTitle("#alpha [unitless]");

	int ntrees = 10;
	float inv_mass;
	float i_child_i, i_child_ii;

	int count=0;
	//Armenteros trials
	float alpha=0;
	float pt=0;
	float pt_ratio=-1;
	//Search through whole set of trees
	for(int i_tree = 1; i_tree<= ntrees; i_tree++){
		//Specific access variables for tree file
		cout << "Now reading file #" << i_tree << "..." << endl;
		//TFile* file = new TFile(Form("../tree_files/tpc/anatree_tpc_01_30_2020_%i.root",i_tree));
		//TFile* file = new TFile(Form("../tree_files/tpc_lambda/anatree_lambda_%i.root",i_tree));
		TFile* file = new TFile(Form("../tree_files/tpc_kaon/anatree_kaonbomb_02_03_2020_%i.root",i_tree));
		TDirectory* directory = (TDirectory*)file->Get("anatree");
		TTree* this_tree = (TTree*)directory->Get("GArAnaTree");
		decayEvt* this_event = new decayEvt();
		this_event->SetBranchAddresses(this_tree);

		for(int i_evt = 0; i_evt < this_tree->GetEntries(); i_evt++){
			this_tree->GetEntry(i_evt);
			for(int i_pdg=0; i_pdg < this_event->PDG->size(); i_pdg++){
				//if(i_pdg == 0) NU_INT_YZ.Fill(this_event->MCVertY->at(0),this_event->MCVertZ->at(0)); //comment this out when working with kaon/lambda bomb anatrees
				if(this_event->PDG->at(i_pdg) == dec_pdg){
					i_child_i = this_event->iChild(pdg_child_i, pdg_par, i_pdg);
					i_child_ii = this_event->iChild(pdg_child_ii,pdg_par,i_pdg);
					if(i_child_i != -1 && i_child_ii != -1){
						pt_ratio=this_event->ArmPod_cut_truth(i_child_i, i_child_ii, mass_child_i, mass_child_ii, mass_par);
						PT_RATIO.Fill(pt_ratio);
						FRAME_BETA.Fill(this_event->Frame_Beta_truth(i_child_i, i_child_ii, mass_child_i, mass_child_ii));
						alpha = this_event->ArmPod_alpha_truth(i_child_i, i_child_ii, mass_child_i, mass_child_ii);
						pt = this_event->ArmPod_pt_truth(i_child_i, i_child_ii, mass_child_i, mass_child_ii);
						ARM_POD.Fill(alpha,pt);	
						INV_MASS.Fill(this_event->InvariantMass_true(i_child_i, i_child_ii, mass_child_i, mass_child_ii));
						count++;
						DECAY_YZ.Fill(this_event->MCPEndY->at(i_pdg), this_event->MCPEndZ->at(i_pdg));
						DECAY_LENGTH.Fill(this_event->DecayLength(i_pdg));
						P_DECAY.Fill(this_event->MagP_Start(i_pdg));
						P_FRAME.Fill(this_event->PFrame_Truth(i_child_i, i_child_ii, i_pdg, mass_child_i, mass_child_ii, mass_par, 0.04)); 
					}
				}	
			}
		}

		delete this_event;
		file->Close();
	//	}	
	}
	cout << "The count was ... " << count << endl;
	TFile* writeFile = new TFile("../output/truth_plots_tpc_kaon.root", "recreate");
	//TFile* writeFile = new TFile("../output/truth_plots_tpc_lambda.root", "recreate");
	NU_INT_YZ.Write();
	DECAY_YZ.Write();
	DECAY_LENGTH.Write();
	P_DECAY.Write();
	P_FRAME.Write();
	INV_MASS.Write();
	ARM_POD.Write();
	PT_RATIO.Write();
	FRAME_BETA.Write();
}

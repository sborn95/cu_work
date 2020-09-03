#include "../src/DecayEvt.C"
#include "TH1F.h"
#include "TDirectory.h"
#include <string>
#include <iostream>

#define TREES 1000

void AnalyzeVertices(int parent){
	int pdg_par, pdg_child_i, pdg_child_ii;
	float mass_par, mass_child_i, mass_child_ii;
	float charge_child_i, charge_child_ii;
	double pval;
	float rlow, rhigh, acc_low, acc_high;
	//Parent # selects correct decay pair pdg numbers, charges, decay frame momentum, masses, etc.
	if(parent == 310){
		pdg_par = 310;
		pdg_child_i = 211;
		pdg_child_ii = -211;
		mass_par = 0.497648;
		mass_child_i = 0.13957;
		mass_child_ii = mass_child_i;
		charge_child_i = 1;
		charge_child_ii = -1;
		pval = 0.205963;
		rlow = 0.2;
		rhigh = 0.6;
		acc_low=0.1;
		acc_high=0.4;
	}
	if(parent == 3122){
		pdg_par = 3122;
		pdg_child_i = 2212;
		pdg_child_ii = -211;
		mass_par = 1.115683;
		mass_child_i = 0.938272;
		mass_child_ii = 0.13957;
		charge_child_i = 1;
		charge_child_ii = -1;
		pval = 0.10058;
		rlow = 1.0;
		rhigh = 1.4;
		acc_low = 0.075;
		acc_high= 0.15;
	
	}
	//Return block, lists the titles for all histograms that this script produces
	float rlow_red=mass_par-0.2;
	float rhigh_red=mass_par+0.2;
	TH1F INV_MASS("inv_mass",Form("(%i) Invariant Mass Assuming (%i,%i) - All Tracks, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),1000,rlow,rhigh);//(0.35 - 0.65 for later cuts maybe)
	INV_MASS.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_CHARGE("inv_mass_q",Form("(%i) Invariant Mass Assuming (%i,%i) - Q_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);//(0.48 - 0.52 for kaons)
	INV_MASS_CHARGE.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_PCUT("inv_mass_pcut",Form("(%i) Invariant Mass Assuming (%i,%i) - P_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);
	INV_MASS_PCUT.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_HITCUT("inv_mass_hitcut",Form("(%i) Invariant Mass Assuming (%i,%i) - CLUS_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);
	INV_MASS_HITCUT.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_COMBO_Q_P("inv_mass_q_p",Form("(%i) Invariant Mass Assuming (%i,%i) - Q_CUT, P_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii), 500, rlow,rhigh);
	INV_MASS_COMBO_Q_P.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_COMBO_Q_CLUS("inv_mass_q_clus",Form("(%i) Invariant Mass Assuming (%i,%i) - Q_CUT, CLUS_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii), 500, rlow,rhigh);
	INV_MASS_COMBO_Q_CLUS.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_COMBO_P_CLUS("inv_mass_p_clus",Form("(%i) Invariant Mass Assuming (%i,%i) - P_CUT, CLUS_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii), 500, rlow,rhigh);
	INV_MASS_COMBO_P_CLUS.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_COMBO_Q_P_CLUS("inv_mass_q_p_clus",Form("(%i) Invariant Mass Assuming (%i,%i) - Q_CUT, P_CUT, CLUS_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii), 500, rlow,rhigh);
	INV_MASS_COMBO_Q_P_CLUS.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	//Armenteros Podolanski trial
	TH2F ARM_POD("arm_pod", Form("%i Armenteros-Podolanski Plot",pdg_par), 150, -1, 1, 150, 0, 0.25);
	ARM_POD.GetYaxis()->SetTitle("p_{T} [GeV/c]");
	ARM_POD.GetXaxis()->SetTitle("#alpha [unitless]");
	TH1F INV_MASS_ARMPOD("inv_mass_armpod",Form("(%i) Invariant Mass Assuming (%i,%i) - ARMPOD_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);//(0.48 - 0.52 for kaons)
	INV_MASS_ARMPOD.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_ARMPOD_2("inv_mass_armpod_2",Form("(%i) Invariant Mass Assuming (%i,%i) - ARMPOD_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);//(0.48 - 0.52 for kaons)
	INV_MASS_ARMPOD_2.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_COMBO_P_ARMPOD("inv_mass_p_armpod",Form("(%i) Invariant Mass Assuming (%i,%i) - P_CUT, ARMPOD_CUT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);//(0.48 - 0.52 for kaons)
	INV_MASS_COMBO_P_ARMPOD.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F INV_MASS_ARMPOD_ACCIDENT("inv_mass_armpod_accident",Form("(%i) Invariant Mass Assuming (%i,%i) - ARMPOD ACCIDENT, All Vertices",pdg_par,pdg_child_i,pdg_child_ii),500,rlow,rhigh);//(0.48 - 0.52 for kaons)
	INV_MASS_ARMPOD_ACCIDENT.GetXaxis()->SetTitle("mass [GeV/c^{2}]");
	TH1F PT_RATIO("pt_ratio",Form("(%i) PT Ratio",pdg_par),500,0,1.2);//(0.48 - 0.52 for kaons)
	PT_RATIO.GetXaxis()->SetTitle("[unitless]");
	TH1F ACCIDENT_RATIO("accident_ratio",Form("(%i) Accident Ratio",pdg_par),500,0,1.2);//(0.48 - 0.52 for kaons)
	ACCIDENT_RATIO.GetXaxis()->SetTitle("[unitless]");
	TH1F FRAME_BETA("frame_beta",Form("(%i) Frame Beta",pdg_par),500,0,1);//(0.48 - 0.52 for kaons)
	FRAME_BETA.GetXaxis()->SetTitle("[unitless]");
	
	//Set up other necessary run details
	int nhits = 100; //parameter, how many hits is the script cutting on
	float pt_ratio = -1;
	float accident_ratio = -1;
	float inv_mass, inv_mass_swp;


	int ntrees = 10;
	//Search through whole set of trees
	for(int i_tree = 1; i_tree<= ntrees; i_tree++){
		cout << "Now reading tree #" << i_tree << "..." << endl;
		//Access tree file
		//TFile* file = new TFile(Form("../tree_files/tpc/anatree_tpc_01_30_2020_%i.root",i_tree));
		//TFile* file = new TFile(Form("/home/susie/Documents/Workspace/tree_files/tpc_lambda/anatree_lambda_%i.root",i_tree));
		//TFile* file = new TFile(Form("/home/susie/Documents/Workspace/tree_files/tpc_lambda/anatreeset_lambdaBomb_1_9_2020/anatree_lambda_%i.root",i_tree));
		TFile* file = new TFile(Form("../tree_files/tpc_kaon/anatree_kaonbomb_02_03_2020_%i.root",i_tree));
		TDirectory* directory = (TDirectory*)file->Get("anatree");
		TTree* this_tree = (TTree*)directory->Get("GArAnaTree");
		decayEvt* this_event = new decayEvt();
		this_event->SetBranchAddresses(this_tree);

		//Armenteros variable
		float alpha=0;
		float pt=0;

		//Loop through events
		for(int i_evt = 0; i_evt < this_tree->GetEntries(); i_evt++){
			this_tree->GetEntry(i_evt);
			int ntracks = this_event->VT_TrackIDNumber->size();
			int count = 0;
			int this_vertIDnum;
			int last_vertIDnum = -1;
			for(int i_track = 0; i_track < ntracks; i_track++){
				//Compare vertex ids -- make matches
				this_vertIDnum = this_event->VT_VertIDNumber->at(i_track); 
				if(this_vertIDnum != last_vertIDnum){
					last_vertIDnum = this_vertIDnum;
					count = 0; //Restart
				}
				else if(this_vertIDnum == last_vertIDnum){
					count++;
					//Compare all tracks from the same vertex
					//Use boolean ends, true = TrackEndPX, false = TrackStartPX
					int i_tr1 = this_event->FindTrack(i_track);
					int i_tr2;
					bool q_cut = false;
					bool p_cut = false;
				       	bool hit_cut = false;
					bool armpod_cut = false;
					bool armpod_cut_2 =false;
					for(int i = i_track-(count); i < i_track; i++){
						//Begin by filling histograms with correct track end information
						i_tr2 = this_event->FindTrack(i);
						//Fill for all combos of track ends
						for(int bool1 = 0; bool1 <=1; bool1++){
							for(int bool2 = 0; bool2 <=1; bool2++){
								inv_mass = this_event->InvariantMass(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii);
								INV_MASS.Fill(inv_mass);
								//Cuts
								//Include one for each possible combination
								if(this_event->ChargeSign_cut(i_tr1, i_tr2, bool1, bool2, charge_child_i, charge_child_ii)){
									INV_MASS_CHARGE.Fill(inv_mass);
									q_cut = true;
									//Also, try out the armenteros plot here
									alpha = this_event->ArmPod_alpha(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii);
									pt = this_event->ArmPod_pt(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii);
									ARM_POD.Fill(alpha,pt);
									pt_ratio = this_event->ArmPod_cut(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii, mass_par);
									if(pt_ratio > 0){
										PT_RATIO.Fill(pt_ratio);
										INV_MASS_ARMPOD.Fill(inv_mass);
										armpod_cut = true;
									}
									accident_ratio = this_event->ArmPod_accident(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii, mass_par, acc_low, acc_high);
									if(accident_ratio > 0){
										ACCIDENT_RATIO.Fill(accident_ratio);
										INV_MASS_ARMPOD_ACCIDENT.Fill(inv_mass);
									}
									if(this_event->ArmPod_cut_2(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii, mass_par)==1){
									//	INV_MASS_ARMPOD_2.Fill(inv_mass);
										armpod_cut_2=true;
									}
								

								}
								if(this_event->PCut(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii, mass_par, 0.040)){
									INV_MASS_PCUT.Fill(inv_mass);
									p_cut = true;
								}
								if(this_event->NClus_cut(i_tr1, i_tr2, nhits)){
									INV_MASS_HITCUT.Fill(inv_mass);
									hit_cut = true;
								}
								if(p_cut && armpod_cut){
									INV_MASS_COMBO_P_ARMPOD.Fill(inv_mass);
								}
								if(p_cut && armpod_cut_2){
									INV_MASS_ARMPOD_2.Fill(inv_mass);
								}
								if(q_cut && p_cut){
									INV_MASS_COMBO_Q_P.Fill(inv_mass);
								}
								if(q_cut && hit_cut){
									INV_MASS_COMBO_Q_CLUS.Fill(inv_mass);
								}
								if(p_cut && hit_cut){
									INV_MASS_COMBO_P_CLUS.Fill(inv_mass);
								}
								if(p_cut && hit_cut && q_cut){
									INV_MASS_COMBO_Q_P_CLUS.Fill(inv_mass);
									FRAME_BETA.Fill(this_event->Frame_Beta(i_tr1, i_tr2, bool1, bool2, mass_child_i, mass_child_ii));
								}
								hit_cut = false;
								q_cut = false;
								p_cut = false;
								armpod_cut = false;
							}
						}
					}	
				}
			}
		}

		delete this_event;
		file->Close();
		//}
	}
	//Write
	TFile* writeFile = new TFile("../output/reco_tpc_kbomb.root","recreate"); 
//	TFile* writeFile = new TFile("../reco_tpc_lbomb.root","recreate"); 
//	TFile* writeFile = new TFile("../reco_tpc_kreal.root","recreate"); 
//	TFile* writeFile = new TFile("../reco_tpc_lreal.root","recreate"); 
	INV_MASS.Write();
	INV_MASS_CHARGE.Write();
	INV_MASS_PCUT.Write();
	INV_MASS_HITCUT.Write();
	INV_MASS_COMBO_Q_P.Write();
	INV_MASS_COMBO_Q_CLUS.Write();
	INV_MASS_COMBO_P_CLUS.Write();
	INV_MASS_COMBO_Q_P_CLUS.Write();
	INV_MASS_ARMPOD.Write();
	INV_MASS_ARMPOD_2.Write();
	INV_MASS_ARMPOD_ACCIDENT.Write();
	INV_MASS_COMBO_P_ARMPOD.Write();
	PT_RATIO.Write();
	FRAME_BETA.Write();
	ARM_POD.Write();
	ACCIDENT_RATIO.Write();
}

#include <vector>
#include <TTree.h>
#include "../include/vect4.h"
#include "vect4.cpp"

class decayEvt {
	public:
		//True/Reco tree variables
		//vector<int>     *branch;
		vector<int> *PDG;
		vector<int> *PDGMother;
		vector<float> *MCVertX;
		vector<float> *MCVertY;
		vector<float> *MCVertZ;
		vector<float> *MCPStartX;
		vector<float> *MCPStartY;
		vector<float> *MCPStartZ;
		vector<float> *MCPEndX;
		vector<float> *MCPEndY;
		vector<float> *MCPEndZ;
		vector<float> *MCPStartPX;
		vector<float> *MCPStartPY;
		vector<float> *MCPStartPZ;
		vector<float> *MCPEndPX;
		vector<float> *MCPEndPY;
		vector<float> *MCPEndPZ;
		vector<ULong64_t> *VT_TrackIDNumber;
		vector<ULong64_t> *VT_VertIDNumber;
		vector<int> *VT_TrackEnd;
		vector<ULong64_t> *TrackIDNumber;
		vector<float> *TrackStartPX;
		vector<float> *TrackEndPX;
		vector<float> *TrackStartPY;
		vector<float> *TrackEndPY;
		vector<float> *TrackStartPZ;
		vector<float> *TrackEndPZ;
		vector<int> *TrackStartQ;
		vector<int> *TrackEndQ;
		vector<int> *NTPCClustersOnTrack;
		// List of branches
                //TBranch     *b_branch;
		TBranch *b_PDG;
		TBranch *b_PDGMother;
		TBranch *b_MCVertX;
		TBranch *b_MCVertY;
		TBranch *b_MCVertZ;
		TBranch *b_MCPStartX;
		TBranch *b_MCPStartY;
		TBranch *b_MCPStartZ;
		TBranch *b_MCPEndX;
		TBranch *b_MCPEndY;
		TBranch *b_MCPEndZ;
		TBranch *b_MCPStartPX;
		TBranch *b_MCPStartPY;
		TBranch *b_MCPStartPZ;
		TBranch *b_MCPEndPX;
		TBranch *b_MCPEndPY;
		TBranch *b_MCPEndPZ;
		TBranch *b_VT_TrackIDNumber;
		TBranch *b_VT_VertIDNumber;
		TBranch *b_VT_TrackEnd;
		TBranch *b_TrackIDNumber;
		TBranch *b_TrackStartPX;
		TBranch *b_TrackEndPX;
		TBranch *b_TrackStartPY;
		TBranch *b_TrackEndPY;
		TBranch *b_TrackStartPZ;
		TBranch *b_TrackEndPZ;
		TBranch *b_TrackStartQ;
		TBranch *b_TrackEndQ;
		TBranch *b_NTPCClustersOnTrack;
		//Constructor
		decayEvt() {
		//Initialize all variables to 0
			//branch = 0;
			PDG = 0;
			PDGMother = 0;
			MCVertX = 0;
			MCVertY = 0;
			MCVertZ = 0;
			MCPStartX = 0;
			MCPStartY = 0;
			MCPStartZ = 0;
			MCPEndX = 0;
			MCPEndY = 0;
			MCPEndZ = 0;
			MCPStartPX = 0;
			MCPStartPY = 0;
			MCPStartPZ = 0;
			MCPEndPX = 0;
			MCPEndPY = 0;
			MCPEndPZ = 0;
			VT_TrackIDNumber = 0;
			VT_VertIDNumber = 0;
			VT_TrackEnd = 0;
			TrackIDNumber = 0;
			TrackStartPX = 0;
 			TrackEndPX = 0;
			TrackStartPY = 0;
 			TrackEndPY = 0;
			TrackStartPZ = 0;
			TrackEndPZ = 0;
			TrackStartQ = 0;
			TrackEndQ = 0;
			NTPCClustersOnTrack = 0;
		}
		
		//Destructor
		~decayEvt() {
		}

		//Fill branches
		void SetBranchAddresses(TTree* inT) {
			inT->SetMakeClass(1);
                        //inT->SetBranchAddress("branch", &branch, &b_branch);
                        inT->SetBranchAddress("PDG", &PDG, &b_PDG);
                        inT->SetBranchAddress("PDGMother", &PDGMother, &b_PDGMother);
                        inT->SetBranchAddress("MCVertX", &MCVertX, &b_MCVertX);
                        inT->SetBranchAddress("MCVertY", &MCVertY, &b_MCVertY);
                        inT->SetBranchAddress("MCVertZ", &MCVertZ, &b_MCVertZ);
                        inT->SetBranchAddress("MCPStartX", &MCPStartX, &b_MCPStartX);
                        inT->SetBranchAddress("MCPStartY", &MCPStartY, &b_MCPStartY);
                        inT->SetBranchAddress("MCPStartZ", &MCPStartZ, &b_MCPStartZ);
                        inT->SetBranchAddress("MCPEndX", &MCPEndX, &b_MCPEndX);
                        inT->SetBranchAddress("MCPEndY", &MCPEndY, &b_MCPEndY);
                        inT->SetBranchAddress("MCPEndZ", &MCPEndZ, &b_MCPEndZ);
                        inT->SetBranchAddress("MCPStartPX", &MCPStartPX, &b_MCPStartPX);
                        inT->SetBranchAddress("MCPStartPY", &MCPStartPY, &b_MCPStartPY);
                        inT->SetBranchAddress("MCPStartPZ", &MCPStartPZ, &b_MCPStartPZ);
                        inT->SetBranchAddress("MCPEndPX", &MCPEndPX, &b_MCPEndPX);
                        inT->SetBranchAddress("MCPEndPY", &MCPEndPY, &b_MCPEndPY);
                        inT->SetBranchAddress("MCPEndPZ", &MCPEndPZ, &b_MCPEndPZ);
                        inT->SetBranchAddress("VT_TrackIDNumber", &VT_TrackIDNumber, &b_VT_TrackIDNumber);
                        inT->SetBranchAddress("VT_VertIDNumber", &VT_VertIDNumber, &b_VT_VertIDNumber);
                        inT->SetBranchAddress("VT_TrackEnd", &VT_TrackEnd, &b_VT_TrackEnd);
			inT->SetBranchAddress("TrackIDNumber",&TrackIDNumber, &b_TrackIDNumber);
			inT->SetBranchAddress("TrackStartPX", &TrackStartPX, &b_TrackStartPX);
                        inT->SetBranchAddress("TrackEndPX", &TrackEndPX, &b_TrackEndPX);
                        inT->SetBranchAddress("TrackStartPY", &TrackStartPY, &b_TrackStartPY);
                        inT->SetBranchAddress("TrackEndPY", &TrackEndPY, &b_TrackEndPY);
                        inT->SetBranchAddress("TrackStartPZ", &TrackStartPZ, &b_TrackStartPZ);
                        inT->SetBranchAddress("TrackEndPZ", &TrackEndPZ, &b_TrackEndPZ);
                        inT->SetBranchAddress("TrackStartQ", &TrackStartQ, &b_TrackStartQ);
                        inT->SetBranchAddress("TrackEndQ", &TrackEndQ, &b_TrackEndQ);
			inT->SetBranchAddress("NTPCClustersOnTrack", &NTPCClustersOnTrack, &b_NTPCClustersOnTrack);
		}
		//Calculation Functions here
		//Truth
		float DecayLength(int i){
			vect4 start, end, diff;
			//Fill start and end vector with truth positions
			start.set_v3(MCPStartX->at(i), MCPStartY->at(i), MCPStartZ->at(i));
			end.set_v3(MCPEndX->at(i), MCPEndY->at(i), MCPEndZ->at(i));
			//Calculate the magnitude of the difference
			diff = end-start;
			return diff.magv3();
		}
		float MagP_Start(int i){
			vect4 pvect;
			pvect.set_v3(MCPStartPX->at(i), MCPStartPY->at(i), MCPStartPZ->at(i));
			return pvect.magv3();
		}
		float MagP_End(int i){
			vect4 pvect;
			pvect.set_v3(MCPEndPX->at(i), MCPEndPY->at(i), MCPEndPZ->at(i));
			return pvect.magv3();
		}
		float InvariantMass_true(int i, int j, float mass1, float mass2){
			vect4 p1,p2,track_sum;
			p1.set_v3(MCPStartPX->at(i), MCPStartPY->at(i), MCPStartPZ->at(i));
			p1.calcset_x0_p(mass1);	
			p2.set_v3(MCPStartPX->at(j), MCPStartPY->at(j), MCPStartPZ->at(j));
			p2.calcset_x0_p(mass2);

			track_sum = p1+p2;
			float inv_mass = (float)sqrt((track_sum*track_sum));
			return inv_mass;
		}
		int iChild(int search, int mother, int i_par){
			int this_pdg, pdg_mother;
			vect4 kid_pos, mother_pos, diff;
			for(int i_kid = i_par; i_kid<PDG->size(); i_kid++){
				this_pdg = PDG->at(i_kid);
				if(this_pdg == search){
					pdg_mother=PDGMother->at(i_kid);
					if(pdg_mother == mother){
						kid_pos.set_v3(MCPStartX->at(i_kid), MCPStartY->at(i_kid), MCPStartZ->at(i_kid));
						mother_pos.set_v3(MCPEndX->at(i_par), MCPEndY->at(i_par), MCPEndZ->at(i_par));
						diff = mother_pos-kid_pos;
						if(diff.magv3() < 1){
							return i_kid;
						}
					}	
				}
			}
			return -1;
		}
		//For
		vect4 SetTrack_P_Truth(int i_tr){
			vect4 tr;
			double px, py, pz;
			px = MCPStartPX->at(i_tr);
			py = MCPStartPY->at(i_tr);
			pz = MCPStartPZ->at(i_tr);
			tr.set_v3(px,py,pz);
			return tr;
		}
		vect4 SetTrack_P_TruthEnd(int i_tr){
			vect4 tr;
			double px, py, pz;
			px = MCPEndPX->at(i_tr);
			py = MCPEndPY->at(i_tr);
			pz = MCPEndPZ->at(i_tr);
			tr.set_v3(px,py,pz);
			return tr;
		}
		bool PCut_Truth(int i_tr1, int i_tr2, float mc1, float mc2, float mass_ex, float range){
			vect4 tr1, tr2, track_sum;
			vect4 tr1_trial, tr2_trial, track_sum_trial;
			float magp_1, magp_2;
			float magp_1_trial, magp_2_trial; 
			float pval = Frame_Pval(mass_ex, mc1, mc2);
			tr1 = SetTrack_P_Truth(i_tr1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_tr2);
			tr2.calcset_x0_p(mc2);
			track_sum = tr1+tr2;
			magp_1 = tr1.mag_p_frame(track_sum);
			magp_2 = tr2.mag_p_frame(track_sum);
			if(magp_1 > (pval-range) && magp_1 < (pval + range)){
				if(magp_2 > (pval-range) && magp_2 < (pval + range)){
					return true;
				}
			}	
			return false;
		}
		float PFrame_Truth(int i_tr1, int i_tr2, int i_par, float mc1, float mc2, float mass_ex, float range){
			vect4 tr1, tr2, track_sum;
			vect4 tr1_trial, tr2_trial, track_sum_trial;
			float magp_1, magp_2;
			float magp_1_trial, magp_2_trial; 
			float pval = Frame_Pval(mass_ex, mc1, mc2);
			tr1 = SetTrack_P_Truth(i_tr1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_tr2);
			tr2.calcset_x0_p(mc2);
			track_sum = tr1+tr2;
			magp_1 = tr1.mag_p_frame(track_sum);
			magp_2 = tr2.mag_p_frame(track_sum);
			cout << "p_expect = " << pval << ", magp_1 = " << magp_1 << ", magp_2 = " << magp_2 << endl;
			track_sum_trial = SetTrack_P_TruthEnd(i_par);
			track_sum_trial.calcset_x0_p(mass_ex);
			cout << "Parent magv3() = " << track_sum.magv3() << endl;
			tr1_trial = tr1.boost(track_sum_trial);
			magp_1=tr1_trial.magv3();
			magp_2 = tr2.mag_p_frame(track_sum_trial);
			tr2_trial = tr2.boost(track_sum_trial);
			magp_2=tr2_trial.magv3();
			cout << "p_expect = " << pval << ", magp_1 = " << magp_1 << ", magp_2 = " << magp_2 << endl;
			return (magp_1+magp_2)/2;
		}
		float ArmPod_alpha_truth(int i_child_i, int i_child_ii, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii;
			float alpha;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P_Truth(i_child_i);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_child_ii);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
		        frame.scalev3(1/frame.magv3());
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			//Return alpha, the asymmetry in longitudinal momentum which is constrained in such a way so as to make an arc
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			cout <<  "ALPHA: alpha" << endl;
			return alpha;
			
		}
		float ArmPod_pt_truth(int i_child_i, int i_child_ii, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i;
			float pT;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P_Truth(i_child_i);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_child_ii);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
		        frame.scalev3(1/frame.magv3());
			pLong_i = tr1|frame;
			pT= sqrt(tr1.magv3()*tr1.magv3()-pLong_i*pLong_i);
			cout << "pT: " << pT << endl;
			//Return pT
			return pT;
		}
		float Frame_Beta_truth(int i_child_i, int i_child_ii, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P_Truth(i_child_i);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_child_ii);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
			//Return Beta
			return frame.beta();
		}
		float ArmPod_cut_truth(int i_child_i, int i_child_ii, float mc1, float mc2, float mPar){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii, pFrame;
			float alpha, pT_sQ, pT_cut_sQ, Beta, a0, r_alpha;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P_Truth(i_child_i);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P_Truth(i_child_ii);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon, get the child pFrame and the frame value for beta
			frame = tr1+tr2;
			pFrame = tr1.mag_p_frame(frame);
			cout << "pFrame is... " << pFrame << endl;
			Beta = frame.beta();
			//Calculate cut variables
			a0 = (mc1*mc1-mc2*mc2)/(mPar*mPar);
			r_alpha = 2*pFrame/(Beta*mPar);
			//Turn frame into a direction, get alpha
		        frame.scalev3(1/frame.magv3());
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			pT_sQ= tr1.magv3()*tr1.magv3()-pLong_i*pLong_i;
			cout << "pT is... " << pT_sQ << endl;
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			//Constraints
			pT_cut_sQ = (1-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame*pFrame;
			cout << "pT_cut is... " << pT_cut_sQ << endl;
			if(a0-r_alpha <= alpha && a0+r_alpha >= alpha){
				if(pT_sQ/pT_cut_sQ < 1.3 && pT_sQ/pT_cut_sQ > 0){
					cout << "RETURNED TRUE, here is ratio " << pT_sQ/pT_cut_sQ << endl;
					return pT_sQ/pT_cut_sQ;
				}
				return -1;
			}
			else{
				cout << "RETURNED FALSE" << endl;
			       	return -1;
			}
				
		}
		//Reco
		float TriangleFunction(float ma, float mb, float mc){
			//A-->B+C
			float tr = (ma+mb+mc)*(ma+mb-mc)*(ma-mb+mc)*(ma-mb-mc);
			return tr;	
		}
		float Frame_Pval(float ma, float mb, float mc){
			//A-->B+C
			float pval = sqrt(TriangleFunction(ma, mb, mc))/(2*ma);
			return pval;
		}	
		/*
		Cut functions here!
		*/
		//These should be integers
		bool ChargeSign_cut(int i1, int i2, int end1, int end2, int expect1, int expect2){
			int q1, q2; 

			if(end1==1){
				q1 = TrackEndQ->at(i1);	
			}
			else{
				q1 = TrackStartQ->at(i1);
			}

			if(end2==1){
				q2 = TrackEndQ->at(i2);
			}
			else{
				q2 = TrackStartQ->at(i2);
			}
			//Can only equal -1 if 1*(-1) 
			if(q1 == expect1 && q2 == expect2) return true;
			else return false; 
		}
		float ArmPod_alpha(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii;
			float alpha;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
		        frame.scalev3(1/frame.magv3());
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			//Return alpha, the asymmetry in longitudinal momentum which is constrained in such a way so as to make an arc
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			return alpha;
			
		}
		float ArmPod_pt(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i;
			float pT;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
		        frame.scalev3(1/frame.magv3());
			pLong_i = tr1|frame;
			pT= sqrt(tr1.magv3()*tr1.magv3()-pLong_i*pLong_i);
			//Return pT
			return pT;
		}
		float Frame_Beta(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2){
			vect4 tr1, tr2, frame; 
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon
			frame = tr1+tr2;
			//Return Beta
			return frame.beta();
		}
		float ArmPod_cut(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2, float mPar){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii, pFrame;
			float alpha, pT_sQ, pT_cut_sQ, Beta, a0, r_alpha, ratio;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon, get the child pFrame and the frame value for beta
			frame = tr1+tr2;
			//pFrame = tr1.mag_p_frame(frame);
			pFrame = tr2.mag_p_frame(frame);
			cout << "pFrame = " << pFrame << endl;
			Beta = frame.beta();
			//Calculate cut variables
			a0 = (mc1*mc1-mc2*mc2)/(mPar*mPar);
			r_alpha = 2*pFrame/(Beta*mPar);
			//Turn frame into a direction, get alpha
		        frame.scalev3(1/frame.magv3());
			cout << "(" << frame.x1() << "," << frame.x2() << "," << frame.x3() << ")" << endl;
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			//pT_sQ = tr1.magv3()*tr1.magv3()-pLong_i*pLong_i;
			pT_sQ = tr2.magv3()*tr2.magv3()-pLong_ii*pLong_ii;
			cout << "pT_sQ = " << pT_sQ << endl; 
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			//Constraints
			pT_cut_sQ = (1-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame*pFrame;
			ratio = pT_sQ/pT_cut_sQ;
			cout << "ratio = " << ratio << "\n\n";
			if(a0-r_alpha <= alpha && a0+r_alpha >= alpha){
				if(ratio < 1.1 && ratio > 0.9){//5 is a good number for the kaon
					return ratio;
				}
				return -1;
			}
			else{
			       	return -1;
			}
				
		}
		int ArmPod_cut_2(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2, float mPar){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii, pFrame;
			float alpha, pT_sQ, pT_cut_sQ, pT_low, pT_high, Beta, a0, r_alpha, ratio, delt;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon, get the child pFrame and the frame value for beta
			frame = tr1+tr2;
			//pFrame = tr1.mag_p_frame(frame);
			pFrame = tr2.mag_p_frame(frame);
			cout << "pFrame = " << pFrame << endl;
			Beta = frame.beta();
			//Calculate cut variables
			a0 = (mc1*mc1-mc2*mc2)/(mPar*mPar);
			r_alpha = 2*pFrame/(Beta*mPar);
			//Turn frame into a direction, get alpha
		        frame.scalev3(1/frame.magv3());
			cout << "(" << frame.x1() << "," << frame.x2() << "," << frame.x3() << ")" << endl;
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			//pT_sQ = tr1.magv3()*tr1.magv3()-pLong_i*pLong_i;
			pT_sQ = tr2.magv3()*tr2.magv3()-pLong_ii*pLong_ii;
			cout << "pT_sQ = " << pT_sQ << endl; 
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			//Constraints
			pT_cut_sQ = (1-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame*pFrame;

			ratio = pT_sQ/pT_cut_sQ;
			cout << "ratio = " << ratio << "\n\n";
			delt=0.025;
			pT_low = (pow((1-delt),2)-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame*pFrame;
			pT_high = (pow((1+delt),2)-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame*pFrame;
			if((1-delt)*r_alpha <= abs(alpha-a0) && (1+delt)*r_alpha >= alpha){
				if(pT_sQ < pT_high && pT_sQ > pT_low){//5 is a good number for the kaon
					return 1;
				}
				return -1;
			}
			else{
			       	return -1;
			}
				
		}
		float ArmPod_accident(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2, float mPar, float acc_low, float acc_high){
			vect4 tr1, tr2, frame; 
			float frame_mag;
			float pLong_i, pLong_ii, pFrame;
			float alpha, pT_sQ, pT_cut_sQ, Beta, a0, r_alpha, ratio;
			//Fill tracks with lab frame child momenta
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			//Set combined 4vector to kaon, get the child pFrame and the frame value for beta
			frame = tr1+tr2;
			//pFrame = tr1.mag_p_frame(frame);
			pFrame = tr2.mag_p_frame(frame);
			cout << "pFrame = " << pFrame << endl;
			Beta = frame.beta();
			//Calculate cut variables
			a0 = (mc1*mc1-mc2*mc2)/(mPar*mPar);
			r_alpha = 2*pFrame/(Beta*mPar);
			//Turn frame into a direction, get alpha
		        frame.scalev3(1/frame.magv3());
			cout << "(" << frame.x1() << "," << frame.x2() << "," << frame.x3() << ")" << endl;
			pLong_i = tr1|frame;
			pLong_ii = tr2|frame;
			//pT_sQ = tr1.magv3()*tr1.magv3()-pLong_i*pLong_i;
			pT_sQ = tr2.magv3()*tr2.magv3()-pLong_ii*pLong_ii;
			cout << "pT_sQ = " << pT_sQ << endl; 
			alpha = (pLong_i-pLong_ii)/(pLong_i+pLong_ii);
			//Constraints
			pT_cut_sQ = (1-(pow((alpha-a0),2)/pow(r_alpha,2)))*pFrame;
			ratio = pT_sQ/pT_cut_sQ;
			cout << "ratio = " << ratio << "\n\n";
			if(a0-r_alpha*1.1 <= alpha && a0+r_alpha*1.1 >= alpha){
				if(ratio < acc_high && ratio > acc_low){//5 is a good number for the kaon
					return ratio;
				}
				return -1;
			}
			else{
			       	return -1;
			}
				
		}
		//If number of hits for each track greater than
		bool NClus_cut(int i1, int i2, int n){
			if(NTPCClustersOnTrack->at(i1) > n){
				if(NTPCClustersOnTrack->at(i2) > n){
					return true;
				}
			}
			return false;

		}
		//For
		bool PCut(int i_tr1, int i_tr2, int end1, int end2, float mc1, float mc2, float mass_ex, float range){
			vect4 tr1, tr2, track_sum;
			vect4 tr1_trial, tr2_trial, track_sum_trial;
			float magp_1, magp_2;
			float magp_1_trial, magp_2_trial; 
			float pval = Frame_Pval(mass_ex, mc1, mc2);
			tr1 = SetTrack_P(i_tr1, end1);
			tr1.calcset_x0_p(mc1);
			tr2 = SetTrack_P(i_tr2, end2);
			tr2.calcset_x0_p(mc2);
			track_sum = tr1+tr2;
			magp_1 = tr1.mag_p_frame(track_sum);
			magp_2 = tr2.mag_p_frame(track_sum);
			if(magp_1 > (pval-range) && magp_1 < (pval + range)){
				if(magp_2 > (pval-range) && magp_2 < (pval + range)){
					return true;
				}
			}	
			return false;
		}
		//Return track id for given VT_TrackIDNumber
		int FindTrack(int i_vt){
			int i_tr;
			ULong64_t vt_trID = VT_TrackIDNumber->at(i_vt);
			for(int i = 0; i<TrackIDNumber->size(); i++){
				i_tr = i;
				if(vt_trID == TrackIDNumber->at(i)){
					return i_tr;
				}
			}
			return -1;
		}
		vect4 SetTrack_P(int i_tr, int end){
			vect4 tr;
			float px, py, pz;
			if(end==0){
				px = TrackStartPX->at(i_tr);
				py = TrackStartPY->at(i_tr);
				pz = TrackStartPZ->at(i_tr);
			}
			else if(end==1){
				px = TrackEndPX->at(i_tr);
				py = TrackEndPY->at(i_tr);
				pz = TrackEndPZ->at(i_tr);
			}
			tr.set_v3(px,py,pz);
			return tr;
		}
		//Return invariant mass
		float InvariantMass(int i_tr1, int i_tr2, int end1, int end2, double rest_mass_1, double rest_mass_2){
			double inv_mass;
			vect4 track1, track2, track_sum;
			
			track1 = SetTrack_P(i_tr1, end1);
			track1.calcset_x0_p(rest_mass_1);	
			track2 = SetTrack_P(i_tr2, end2);
			track2.calcset_x0_p(rest_mass_2);	
			
			track_sum = track1+track2;
			inv_mass = sqrt((track_sum*track_sum));
			return (float)inv_mass;
		}
};

#include "../src/DecayEvt.C"
#include "TH1F.h"
#include "TDirectory.h"
#include <string>
#include <iostream>

int run(int parent){
	TH2F ARM_POD("arm_pod", Form("%i Armenteros-Podolanski Cut",parent), 150, -1.3, 1.3, 150, 0, 0.25);
	ARM_POD.GetYaxis()->SetTitle("p_{T} [GeV/c]");
	ARM_POD.GetXaxis()->SetTitle("#alpha [unitless]");
	TH2F ARM_POD_2("arm_pod_2", Form("%i Armenteros-Podolanski Cut",parent), 150, -1.3, 1.3, 150, 0, 0.25);
	ARM_POD_2.GetYaxis()->SetTitle("p_{T} [GeV/c]");
	ARM_POD_2.GetXaxis()->SetTitle("#alpha [unitless]");
	float mPar = 0.497648;
	float mc1 = 0.13957;
	float mc2 = mc1;
	int charge_child_i = 1;
	int charge_child_ii = -1;
	float pval = 0.205963;
	TRandom3 rand;
	float a0 = (mc1*mc1-mc2*mc2)/(mPar*mPar);
	float r_alpha = 2*pval/(mPar);
	float scale;
	float alpha, pT_cut_sQ, pT,r_rand,alpha_2, pT_2;
	for(int i = 0; i<10000; i++){
		alpha = rand.Uniform(a0-(1.1)*r_alpha,a0+(1.1)*r_alpha);
		pT_cut_sQ = (1-(pow((alpha-a0),2)/pow(r_alpha,2)))*pow(pval,2);
		pT = sqrt(rand.Uniform(0.9*pT_cut_sQ,1.1*pT_cut_sQ));
		ARM_POD.Fill(alpha,pT);
		r_rand = rand.Uniform(0.9,1.1);
		alpha_2 = rand.Uniform(a0-r_rand*r_alpha,a0+r_rand*r_alpha);
		pT_2 = sqrt((r_rand*r_rand-(pow((alpha_2-a0),2)/pow(r_alpha,2)))*pow(pval,2));
		ARM_POD_2.Fill(alpha_2,pT_2);
	}

	TFile* writeFile = new TFile("../output/armpod_expect.root","recreate"); 
	ARM_POD.Write();
	ARM_POD_2.Write();
	return 0;
}

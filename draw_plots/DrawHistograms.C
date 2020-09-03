#include <iostream>
#include "TH1.h"
#include "TH2.h"
#include "TStyle.h"
#include "TRandom3.h"
#include <string>
using namespace std;

void SetPalette(){
    const Int_t NRGBs = 5;
    const Int_t NCont = 104;
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}

//Note: most momentum plot options are do not need to be used to plot momentum, that was just the original use. 
TH2F* Draw2DMomentum(int num, string filename,string histname){
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetYaxis()->SetTitleOffset(1.4);
	//Arr does not seem to work.I don't know if I care that much. 
	TCanvas* c1 = new TCanvas("c1","c1",700,700);
	h->Draw("COLZ");
	return h;
}
TH2F* Draw2DMomentumSet(int num, int pid, int choice, string histname){
	gROOT->Reset();
	SetPalette();
	string filename;
	if(pid == 310){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetYaxis()->SetTitleOffset(1.4);
	//TFile* myFile = new TFile("/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc.root");
	h->GetYaxis()->SetTitleOffset(1.4);
	//Arr does not seem to work.I don't know if I care that much. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",700,700);
	h->Draw("COLZ");
	return h;
}
TH2F* Draw2DMomentumLogZ(int num, int pid, int choice, string histname){
	gROOT->Reset();
	SetPalette();
	string filename;
	if(pid == 310){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetYaxis()->SetTitleOffset(1.4);
	//Arr does not seem to work.I don't know if I care that much. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",700,700);
	gPad->SetLogz();
	h->Draw("COLZ");
	return h;
}
TH2F* Draw2DMomentumMaxLimit(int num, int pid, int choice, int low, int high, string histname){
	gROOT->Reset();
	SetPalette();
	string filename;
	if(pid == 310){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetZaxis()->SetRangeUser(low,high);
	h->GetYaxis()->SetTitleOffset(1.4);
	//Arr does not seem to work.I don't know if I care that much. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",700,700);
	h->Draw("COLZ");
	return h;
}
TH2F* Draw2DMomentumMaxLimitLogZ(int num, int pid, int choice, int low, int high, string histname){
	gROOT->Reset();
	SetPalette();
	string filename;
	if(pid == 310){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		if(choice==0){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		}
		else if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetZaxis()->SetRangeUser(low,high);
	h->GetYaxis()->SetTitleOffset(1.4);
	//Arr does not seem to work.I don't know if I care that much. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",700,700);
	gPad->SetLogz();
	h->Draw("COLZ");
	return h;
}
TH2F* Draw2DSingleColor(int num,string filename, string histname,Style_t style, Color_t color){
	TFile* myFile = new TFile(filename.c_str());
	TH2F* h = (TH2F*)myFile->Get(histname.c_str());
	h->GetYaxis()->SetTitleOffset(1.4);
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	h->SetMarkerStyle(style);
	h->SetMarkerColor(color);
	h->Draw();
	return h;
}
TH1F* Draw1DGeneric(int num, char* filename, char* histname, Color_t color){
	TFile* myFile = new TFile(filename);
	TH1F* h = (TH1F*)myFile->Get(histname);
	//This works. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	h->SetLineColor(color);
	h->SetLineWidth(4);
	h->Draw();
	return h;
}
TH1F* Draw1DSameCanvas(int num, char* filename1,char* filename2, char* histname, Color_t color){
	TFile* myFile1 = new TFile(filename1);
	TH1F* h1 = (TH1F*)myFile1->Get(histname);
	TFile* myFile2 = new TFile(filename2);
	TH1F* h2 = (TH1F*)myFile2->Get(histname);
	//This works. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	//h1->SetLineColor(color);
	//h1->SetLineWidth(4);
	h1->SetFillColor(kBlack);
	h2->SetFillColorAlpha(kRed,0.35);
	h1->Draw();
	h2->Draw("same");
	return h1;
}
TH1F* Fit1DGeneric(int num, Color_t color=kBlack){
	TFile* myFile = new TFile("bomb_histograms.root");
	TF1* fGaus = new TF1("f1","[0]*TMath::Gaus(x,[1],[2],0) + [3]",0,1);
	double mean = 0;
	double sigma = 1; 
	double scale = 1;
	double offset = 0;
	cout << "set mean:" << endl;
	cin >> mean;
	cout << "set sigma:" << endl;
	cin >> sigma;
	cout << "set scale:" << endl;
	cin >> scale; 
	cout << "set offset:" << endl;
	cin >> offset;

	fGaus->SetParameters(scale, mean, sigma, offset);

	TH1F* h = (TH1F*)myFile->Get("invMass_r");
	//This works. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	h->SetLineColor(color);
	h->SetLineWidth(4);
	h->Fit("f1");
	h->Draw();
	return h;
}


TH1F* Fit1DGaus2(int num,int pid,int choice,string histname, Color_t color){
	string filename, inv;
	float scale, mean, sigma, offset;
	if(pid == 310){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		scale=10000;
		mean=0.497;
		sigma=0.02;
		offset=250;
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		scale=1000;
		mean=1.115;
		sigma=0.01;
		offset=250;
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TF1* fGaus = new TF1("f1","[0]*TMath::Gaus(x,[1],[2],0) + [3]",0,1);
	fGaus->SetParNames("scale","mean","sigma","offset");
	fGaus->SetParameters(10000,0.497,0.02,250);
	TH1F* h = (TH1F*)myFile->Get(histname.c_str());
	//This works. 
	
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	h->SetLineColor(color);
	h->SetLineWidth(4);
	gStyle->SetOptStat("ne");
	gStyle->SetOptFit(0011);
	h->Fit("f1");
	h->Draw(0);
	//c1->SaveAs("cdr_inv_mass.pdf");	
	return h;
}
TH2F* DrawCircle(float rad,float range, float n,Color_t color){
  	TH2F* h = new TH2F("h","circle",sqrt(n),-range,range,sqrt(n),-range,range);
  	TRandom3* myRand = new TRandom3(0);
  	double x,y;
  	for(int i = 0; i<10000;i++){
  		myRand->Circle(x,y,rad);
  		h->Fill(x,y,100);
  	}
  	TCanvas* c1 = new TCanvas("c1","c1",750,500);
  	h->SetMarkerStyle(kFullDotSmall);
  	h->SetMarkerColor(color);
  	h->Draw();
  	return h;
}
  //A specific draw option for truth information
void DrawSameCanvas(string title, bool atStart){
  	TH2F* h1 = Draw2DMomentum(1,"/home/susie/Documents/temp/histos_tpc.root","nuYZ");
  	TH2F* h2 = Draw2DSingleColor(2,"/home/susie/Documents/temp/histos_tpc.root","kppYZ",47,kRed);
  	TH2F* h3 = Draw2DSingleColor(3,"/home/susie/Documents/temp/histos_tpc.root","kppYZ_f",47,kGreen);
         	TCanvas* c1 = new TCanvas("c1",title.c_str(),500,500);
  	h1->GetXaxis()->SetTickSize(0.08);
  	h1->GetXaxis()->SetLabelSize(0.03);
  	h1->GetYaxis()->SetTickSize(0.08);
  	h1->GetYaxis()->SetLabelSize(0.03);
  	h1->SetStats(0);
	h1->SetTitle(title.c_str());
	h1->Draw("COL");
	if(atStart){
		h2->Draw("same");
	}
	else{
		h3->Draw("same");
	}	
}


void DrawSameCanvas_cut_end(string title){
	//TH2F* h1 = Draw2DMomentum(1,"/home/susie/Documents/temp/Hisots_ECAL.root","nuYZ");
	TH2F* h1 = Draw2DMomentum(1,"/home/susie/Documents/temp/Histos_TPC.root","nuYZ");
	TH2F* h2 = DrawCircle(255,500,100000,kRed);
	//TH2F* h3 = Draw2DSingleColor(3,"/home/susie/Documents/temp/Histos_ECAL.root","kppYZ_f",47,kGreen);
	TH2F* h3 = Draw2DSingleColor(3,"/home/susie/Documents/temp/Histos_TPC.root","kppYZ_f",47,kGreen);
       	TCanvas* c1 = new TCanvas("c1",title.c_str(),500,500);
	h1->GetXaxis()->SetTickSize(0.08);
	h1->GetXaxis()->SetLabelSize(0.03);
	h1->GetYaxis()->SetTickSize(0.08);
	h1->GetYaxis()->SetLabelSize(0.03);
	h1->SetStats(0);
	h1->SetTitle(title.c_str());
	h1->Draw("COL");
	h2->SetStats(0);
	h2->Draw("same");
	h3->Draw("same");	
}

void DrawSameCanvas_cut_start(string title){
	//TH2F* h1 = Draw2DMomentum(1,"/home/susie/Documents/temp/Hisots_ECAL.root","nuYZ");
	TH2F* h1 = Draw2DMomentum(1,"/home/susie/Documents/temp/Histos_TPC.root","nuYZ");
	TH2F* h2 = DrawCircle(255,500,100000,kRed);
	//TH2F* h3 = Draw2DSingleColor(3,"/home/susie/Documents/temp/Histos_ECAL.root","kppYZ",47,kRed);
	TH2F* h3 = Draw2DSingleColor(3,"/home/susie/Documents/temp/Histos_TPC.root","kppYZ_f",47,kRed);
       	TCanvas* c1 = new TCanvas("c1",title.c_str(),500,500);
	h1->GetXaxis()->SetTickSize(0.08);
	h1->GetXaxis()->SetLabelSize(0.03);
	h1->GetYaxis()->SetTickSize(0.08);
	h1->GetYaxis()->SetLabelSize(0.03);
	h1->SetStats(0);
	h1->SetTitle(title.c_str());
	h1->Draw("COL");
	h2->SetStats(0);
	h2->Draw("same");
	h3->Draw("same");	
}
void DrawSameCanvas_Reco_Inv(int num, int pid, int choice, string histname, Color_t color){
	string filename, inv;
	if(pid == 310){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH1F* h = (TH1F*)myFile->Get(histname.c_str());

	//This works. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	h->SetLineColor(color);
	h->SetLineWidth(4);
	h->Draw();
	return h;
}

void DrawSameCanvas_Truth_Reco_Inv(int num, int pid, int choice, string histname, Color_t color){
	string filename, inv;
	if(pid == 310){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_kaon.root";
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_kreal.root";
		}
	}
	if(pid == 3122){
		inv = "/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/truth_plots_tpc_lambda.root";
		if(choice==1){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lbomb.root";
		}
		else if(choice ==2){
			filename="/home/susie/Documents/Workspace/run/kaon_analysis/v02_02_00/run/reco_tpc_lreal.root";
		}
	}
	TFile* myFile = new TFile(filename.c_str());
	TH1F* h = (TH1F*)myFile->Get(histname.c_str());

	TFile* myFile2 = new TFile(inv.c_str());
	TH1F* h2 = (TH1F*)myFile2->Get("inv_mass");
	//This works. 
	TCanvas* c1 = new TCanvas(Form("c%i",num),"c1",500,500);
	c1->SetGrid();
	h->SetLineColor(color);
	h->SetLineWidth(4);
	h2->SetLineColor(kRed);
	h2->SetLineWidth(2);
	h->Draw();
	h2->Draw("same");
	return h;
}


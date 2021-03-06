#include "TROOT.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TPaveStats.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TList.h"
#include "TLegendEntry.h"
#include "string.h"
#include <iostream>
#include "TTreeReader.h"
#include "TChain.h"
#include "TProfile.h"
#include <cmath>
#include "TProfile2D.h"
#include "TH2D.h"


void HFRecHit2SimHit(const char *infile1, const char *infile2, const char *outfile, const char *flag1 = "single", const char *flag2 = "single", const char *process = "full"){

  bool debug = false;
  bool threshold = true;

  TTreeReader *tReader1, *tReader2;

  int nSkims = 10;
  bool skim = false;
  int cntSkimHB1 = 0;
  int cntSkimHB2 = 0;
  int cntSkimHE1 = 0;
  int cntSkimHE2 = 0;
  int cntSkimHE3 = 0;


  if(!strcmp(process,"skim")) skim = true;


  if(!strcmp(flag1,"single")){

    TFile *f1 = new TFile(infile1);
    if(f1->IsZombie()){
      cout << "Root file: " << infile1 << " not found!" << endl;
      return;
    }
    tReader1 = new TTreeReader("RecHitTree",f1);
    if(debug) cout << "Created tReader1 from " << infile1 << endl;

  } else if(!strcmp(flag1,"list")){

    ifstream in1;
    in1.open(infile1);
    if(!in1.is_open()){
      cout << "Cannot open list file: " << infile1 << endl;
      return;  
    }

    TChain *chain1 = new TChain("RecHitTree");
    
    string line1;
    while(in1.good()){
      if(!std::getline(in1,line1)) break; // We read a line from the file
      if(!chain1->Add(line1.c_str())){
	cout << "Problem loading tree from " << line1 << endl;
      }else{
	cout << "Adding file: " << line1 << "..." << endl;
      }
      
    }
    
    in1.close();
    
    tReader1 = new TTreeReader((TTree *)chain1);
    cout << "Finished loading files." << endl;
  } else {
    cout << "Unknown option: " << flag1 << endl;
    return;
  }

  if(!strcmp(flag2,"single")){

    TFile *f2 = new TFile(infile2);
    if(f2->IsZombie()){
      cout << "Root file: " << infile2 << " not found!" << endl;
      return;
    }
    tReader2 = new TTreeReader("hcalSimHitTree/SimHitTree",f2);
    cout << "Created tReader2 from " << infile2 << endl;

  } else if(!strcmp(flag2,"list")){

    ifstream in2;
    in2.open(infile2);
    if(!in2.is_open()){
      cout << "Cannot open list file: " << infile2 << endl;
      return;  
    }

    TChain *chain2 = new TChain("hcalSimHitTree/SimHitTree");
    
    string line2;
    while(in2.good()){
      if(!std::getline(in2,line2)) break; // We read a line from the file
      if(!chain2->Add(line2.c_str())){
	cout << "Problem loading tree from " << line2 << endl;
      }else{
	cout << "Adding file: " << line2 << "..." << endl;
      }
      
    }
    
    in2.close();
    
    tReader2 = new TTreeReader((TTree *)chain2);
    cout << "Finished loading files." << endl;
  } else {
    cout << "Unknown option: " << flag2 << endl;
    return;
  }


  TFile *fout = new TFile(outfile, "NEW");
  if(fout->IsZombie()){
    cout << "Root file: " << outfile << " cannot be created!" << endl;
    return;
  }
      

  //Define the branchs to be read

  TTreeReaderValue<Int_t> eventID1(*tReader1, "event");
  TTreeReaderValue<Int_t> lumiID1(*tReader1, "lumi");
  TTreeReaderValue<Int_t> runID1(*tReader1, "run");  

  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_En1(*tReader1, "recHitHB1_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_EnRAW1(*tReader1, "recHitHB1_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB1_ieta1(*tReader1, "recHitHB1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB1_iphi1(*tReader1, "recHitHB1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_time1(*tReader1, "recHitHB1_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_En1(*tReader1, "recHitHB2_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_EnRAW1(*tReader1, "recHitHB2_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB2_ieta1(*tReader1, "recHitHB2_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB2_iphi1(*tReader1, "recHitHB2_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_time1(*tReader1, "recHitHB2_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_En1(*tReader1, "recHitHE1_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_EnRAW1(*tReader1, "recHitHE1_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE1_ieta1(*tReader1, "recHitHE1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE1_iphi1(*tReader1, "recHitHE1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_time1(*tReader1, "recHitHE1_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_En1(*tReader1, "recHitHE2_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_EnRAW1(*tReader1, "recHitHE2_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE2_ieta1(*tReader1, "recHitHE2_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE2_iphi1(*tReader1, "recHitHE2_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_time1(*tReader1, "recHitHE2_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_En1(*tReader1, "recHitHE3_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_EnRAW1(*tReader1, "recHitHE3_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE3_ieta1(*tReader1, "recHitHE3_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE3_iphi1(*tReader1, "recHitHE3_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_time1(*tReader1, "recHitHE3_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHF1_En1(*tReader1, "recHitHF1_En");
  //TTreeReaderValue<std::vector<int>> readRecHitsHF1_ieta1(*tReader1, "recHitHF1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHF1_iphi1(*tReader1, "recHitHF1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHF1_time1(*tReader1, "recHitHF1_time");

  TTreeReaderValue<std::vector<float>> readRecHitsHF_En1(*tReader1, "recHitHF_En");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_ieta1(*tReader1, "recHitHF_ieta");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_iphi1(*tReader1, "recHitHF_iphi");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_depth1(*tReader1, "recHitHF_depth");
  //TTreeReaderValue<std::vector<float>> readRecHitsHF_time(*tReader1, "recHitHF_time");


  //TTreeReaderValue<std::vector<float>> readRecHitsHO_En1(*tReader1, "recHitHO_En");
  //TTreeReaderValue<std::vector<int>> readRecHitsHO_ieta1(*tReader1, "recHitHO_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHO_iphi1(*tReader1, "recHitHO_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHO_time1(*tReader1, "recHitHO_time");

  //Tree2
  TTreeReaderValue<Int_t> eventID2(*tReader2, "event");
  TTreeReaderValue<Int_t> lumiID2(*tReader2, "lumi");
  TTreeReaderValue<Int_t> runID2(*tReader2, "run");  

  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_En2(*tReader2, "recHitHB1_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_EnRAW2(*tReader2, "recHitHB1_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB1_ieta2(*tReader2, "recHitHB1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB1_iphi2(*tReader2, "recHitHB1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB1_time2(*tReader2, "recHitHB1_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_En2(*tReader2, "recHitHB2_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_EnRAW2(*tReader2, "recHitHB2_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB2_ieta2(*tReader2, "recHitHB2_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHB2_iphi2(*tReader2, "recHitHB2_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHB2_time2(*tReader2, "recHitHB2_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_En2(*tReader2, "recHitHE1_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_EnRAW2(*tReader2, "recHitHE1_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE1_ieta2(*tReader2, "recHitHE1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE1_iphi2(*tReader2, "recHitHE1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE1_time2(*tReader2, "recHitHE1_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_En2(*tReader2, "recHitHE2_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_EnRAW2(*tReader2, "recHitHE2_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE2_ieta2(*tReader2, "recHitHE2_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE2_iphi2(*tReader2, "recHitHE2_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE2_time2(*tReader2, "recHitHE2_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_En2(*tReader2, "recHitHE3_En");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_EnRAW2(*tReader2, "recHitHE3_EnRAW");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE3_ieta2(*tReader2, "recHitHE3_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHE3_iphi2(*tReader2, "recHitHE3_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHE3_time2(*tReader2, "recHitHE3_time");

  //TTreeReaderValue<std::vector<float>> readRecHitsHF1_En2(*tReader2, "recHitHF1_En");
  //TTreeReaderValue<std::vector<int>> readRecHitsHF1_ieta2(*tReader2, "recHitHF1_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHF1_iphi2(*tReader2, "recHitHF1_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHF1_time2(*tReader2, "recHitHF1_time");

  TTreeReaderValue<std::vector<float>> readRecHitsHF_En2(*tReader2, "SimHitsEn");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_ieta2(*tReader2, "SimHitsIeta");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_iphi2(*tReader2, "SimHitsIphi");
  TTreeReaderValue<std::vector<int>> readRecHitsHF_depth2(*tReader2, "SimHitsDepth");
  //TTreeReaderValue<std::vector<float>> readRecHitsHF_time(*tReader2, "recHitHF_time");


  //TTreeReaderValue<std::vector<float>> readRecHitsHO_En2(*tReader2, "recHitHO_En");
  //TTreeReaderValue<std::vector<int>> readRecHitsHO_ieta2(*tReader2, "recHitHO_ieta");
  //TTreeReaderValue<std::vector<int>> readRecHitsHO_iphi2(*tReader2, "recHitHO_iphi");
  //TTreeReaderValue<std::vector<float>> readRecHitsHO_time2(*tReader2, "recHitHO_time");


  fout->cd();

  //TH2D *recHitEnergyHB = new TH2D("recHitEnergyHB","recHitEnergyHB",300,-20,100,300,-20,100);
  //TH2D *recHitEnergyHE = new TH2D("recHitEnergyHE","recHitEnergyHE",550,-20,200,550,-20,200);
  TH2D *recHitEnergyHF = new TH2D("recHitEnergyHF","recHitEnergyHF",81,-0.5,80.5,41,-0.5,81.5);
  //TH2D *recHitEnergyHO = new TH2D("recHitEnergyHO","recHitEnergyHO",300,-20,100,300,-20,100);

  //TH2D *recHitEnergyRAWHB = new TH2D("recHitEnergyRAWHB","recHitEnergyRAWHB",300,-20,100,300,-20,100);
  //TH2D *recHitEnergyRAWHE = new TH2D("recHitEnergyRAWHE","recHitEnergyRAWHE",550,-20,200,550,-20,200);

  //TH2D *recHitEnergyHB1 = new TH2D("recHitEnergyHB1","recHitEnergyHB1",300,-20,100,300,-20,100);
  //TH2D *recHitEnergyHB2 = new TH2D("recHitEnergyHB2","recHitEnergyHB2",300,-20,100,300,-20,100);

  //TH2D *recHitEnergyHE1 = new TH2D("recHitEnergyHE1","recHitEnergyHE1",550,-20,200,550,-20,200);
  //TH2D *recHitEnergyHE2 = new TH2D("recHitEnergyHE2","recHitEnergyHE2",550,-20,200,550,-20,200);
  //TH2D *recHitEnergyHE3 = new TH2D("recHitEnergyHE3","recHitEnergyHE3",550,-20,200,550,-20,200);

  //TH2D *recHitEnergyRAWHB1 = new TH2D("recHitEnergyRAWHB1","recHitEnergyRAWHB1",300,-20,100,300,-20,100);
  //TH2D *recHitEnergyRAWHB2 = new TH2D("recHitEnergyRAWHB2","recHitEnergyRAWHB2",300,-20,100,300,-20,100);

  //TH2D *recHitEnergyRAWHE1 = new TH2D("recHitEnergyRAWHE1","recHitEnergyRAWHE1",550,-20,200,550,-20,200);
  //TH2D *recHitEnergyRAWHE2 = new TH2D("recHitEnergyRAWHE2","recHitEnergyRAWHE2",550,-20,200,550,-20,200);
  //TH2D *recHitEnergyRAWHE3 = new TH2D("recHitEnergyRAWHE3","recHitEnergyRAWHE3",550,-20,200,550,-20,200);

  TH2D *recHitEnergyHF1 = new TH2D("recHitEnergyHF1","recHitEnergyHF1",81,-0.5,80.5,41,-0.5,81.5);
  TH2D *recHitEnergyHF2 = new TH2D("recHitEnergyHF2","recHitEnergyHF2",81,-0.5,80.5,41,-0.5,81.5);

  //TH2D *recHitTimingHB = new TH2D("recHitTimingHB","recHitTimingHB",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHB1 = new TH2D("recHitTimingHB1","recHitTimingHB1",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHB2 = new TH2D("recHitTimingHB2","recHitTimingHB2",350,-48,92,350,-48,90);

  //TH2D *recHitTimingHE = new TH2D("recHitTimingHE","recHitTimingHE",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHE1 = new TH2D("recHitTimingHE1","recHitTimingHE1",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHE2 = new TH2D("recHitTimingHE2","recHitTimingHE2",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHE3 = new TH2D("recHitTimingHE3","recHitTimingHE3",350,-48,92,350,-48,90);

  //TH2D *recHitTimingHF = new TH2D("recHitTimingHF","recHitTimingHF",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHF1 = new TH2D("recHitTimingHF1","recHitTimingHF1",350,-48,92,350,-48,90);
  //TH2D *recHitTimingHF2 = new TH2D("recHitTimingHF2","recHitTimingHF2",350,-48,92,350,-48,90);

  //TH2D *recHitTimingHO = new TH2D("recHitTimingHO","recHitTimingHO",350,-48,92,350,-48,90);

  //TProfile *meanEnergy_vs_ieta_HB_1 = new TProfile("meanEnergy_vs_ieta_HB_1","meanEnergy_vs_ieta_HB_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HB_2 = new TProfile("meanEnergy_vs_ieta_HB_2","meanEnergy_vs_ieta_HB_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HB1_1 = new TProfile("meanEnergy_vs_ieta_HB1_1","meanEnergy_vs_ieta_HB1_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HB1_2 = new TProfile("meanEnergy_vs_ieta_HB1_2","meanEnergy_vs_ieta_HB1_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HB2_1 = new TProfile("meanEnergy_vs_ieta_HB2_1","meanEnergy_vs_ieta_HB2_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HB2_2 = new TProfile("meanEnergy_vs_ieta_HB2_2","meanEnergy_vs_ieta_HB2_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE_1 = new TProfile("meanEnergy_vs_ieta_HE_1","meanEnergy_vs_ieta_HE_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE_2 = new TProfile("meanEnergy_vs_ieta_HE_2","meanEnergy_vs_ieta_HE_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE1_1 = new TProfile("meanEnergy_vs_ieta_HE1_1","meanEnergy_vs_ieta_HE1_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE1_2 = new TProfile("meanEnergy_vs_ieta_HE1_2","meanEnergy_vs_ieta_HE1_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE2_1 = new TProfile("meanEnergy_vs_ieta_HE2_1","meanEnergy_vs_ieta_HE2_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE2_2 = new TProfile("meanEnergy_vs_ieta_HE2_2","meanEnergy_vs_ieta_HE2_2",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE3_1 = new TProfile("meanEnergy_vs_ieta_HE3_1","meanEnergy_vs_ieta_HE3_1",71,-30.5,30.5);
  //TProfile *meanEnergy_vs_ieta_HE3_2 = new TProfile("meanEnergy_vs_ieta_HE3_2","meanEnergy_vs_ieta_HE3_2",71,-30.5,30.5);

  cout << "Filling histograms..." << endl;
  
  //We loop over all of the events and fill the histograms
  int numRecHits = 0;

  int recHitIeta = 0;
  int recHitIphi = 0;
  int recHitDepth = 0;
  float recHitEnergy = 0;
  float runningSum = 0;

  long tree2BookMark = 0;
  bool matched = false;
  bool wrapped = false;
  int partialMatch = 0; //Identify the SimHit depth that has been matched.

  //This might be a bit of a kludge...
  long tree2first;

  if(!tReader2->Next()){
	cout << "No branches can be read from the tree given in " << infile2 << "!" << endl;
	return;
  } else {
	tree2first = tReader2->GetCurrentEntry();
  }

  //Let's track some information about the trees
  int tree1Events = 0;
  int matchedEvents = 0;
  int unmatchedEvents = 0;
  bool continueLoop = true;
  
  while(tReader1->Next()&&continueLoop){

    if(debug && (tree1Events > 5000)) break;	
    tree1Events++;

   if(debug) cout << "Processing event: " << tree1Events << ", " << *runID1 << ":" << *lumiID1 << ":" << *eventID1 << endl;

    //We look for a matching event in the second tree
    //Book mark the current event, if we come back here, there is not a matching RecHit
    tree2BookMark = tReader2->GetCurrentEntry();
    matched = false;
    wrapped = false;

    //We iterate over Tree2 until we find a match or discover no matches.
    while(!matched && !(wrapped && (tree2BookMark == tReader2->GetCurrentEntry()))){
	if((*eventID1 == *eventID2)&&(*runID1 == *runID2)){
		//Mark these events as matching, the break out of the loop
                matched = true;
                break;
	} else if(!matched){
		//Advance tree2 and check whether we have reached the end
		//wrap around to the beginning
		if(!tReader2->Next()){
			wrapped = true;
			tReader2->SetEntry(tree2first);
		}
	}
	
	

    }

    //If we couldn't find the a matching event, we procede to the next
    if(!matched){
	cout << "No matching event in " << infile2 << " for event " << *runID1 << ":" << *lumiID1 << ":" << *eventID1 << ". Proceding to next event." << endl;
	unmatchedEvents++;
	continue;
    } else {
	matchedEvents++;
    }

    if(tree1Events % 500 == 0) cout << "Added " << tree1Events << " events." << endl;

    if(skim) continueLoop = false;

    //Now for each subdet and depth, we will match the recHits
    bool rmatched = false;
    int  v2BookMark = 0;
    int partialMatch = 0;
    double runningSum = 0;

    if(!skim) for(int idx1 = 0; idx1 < (*readRecHitsHF_En1).size(); idx1++){
	int ieta1 = (*readRecHitsHF_ieta1).at(idx1);
	int iphi1 = (*readRecHitsHF_iphi1).at(idx1);
	int depth1 = (*readRecHitsHF_depth1).at(idx1);

	rmatched = false;
	partialMatch = 0;
	runningSum = 0;

	//assuming that the ordering of the recHits might be similar between releases, this might save us time.
        //in other words, instead of starting from the begining each time, we are going to look in the second vector
	//where we left off.

	int v2Size = (*readRecHitsHF_En2).size();
	for(int idx2 = 0; idx2 < v2Size; idx2++){
		int ieta2 = (*readRecHitsHF_ieta2).at((v2BookMark + idx2) % v2Size);
		int iphi2 = (*readRecHitsHF_iphi2).at((v2BookMark + idx2) % v2Size);
		int depth2 = (*readRecHitsHF_depth2).at((v2BookMark + idx2) % v2Size);

		if( (ieta1 == ieta2) && (iphi1 == iphi2) ){
			if((depth1 == 1) && !(depth2 == 1 || depth2 == 3)) continue; 
			if((depth1 == 2) && !(depth2 == 2 || depth2 == 4)) continue; 
			
			if(partialMatch != 0){
				rmatched = true;
				v2BookMark = (v2BookMark +idx2) % v2Size;
				//std::cout << "2nd Match iphi = " << iphi1 << ", ieta " << ieta1 << ", Rdepth " << depth1 << ", Sdepth " << depth2 << std::endl;
				break; //We don't need to test any of the other recHits
			} else {
				partialMatch = depth2;
				runningSum = (*readRecHitsHF_depth2).at((v2BookMark + idx2) % v2Size);
			}
		}
	}

	if(rmatched || (partialMatch != 0)){
		//Get the histogram bin width, for decision on comparison
		double enWidth = 2; // recHitEnergyHF2->GetBinWidth(1);
		//double timeWidth = 1; // recHitTimingHF2->GetBinWidth(1);		

		//Fill the Histograms
		double En1 = (*readRecHitsHF_En1).at(idx1);
		double En2 = 0;
		if(rmatched){
			En2 = (*readRecHitsHF_En2).at(v2BookMark);	
		}
		if(partialMatch != 0){
			//std::cout << "1st depth : " << En2 << " 2nd depth: " << runningSum << std::endl;
			En2 += runningSum;
			//std::cout << "1st Match iphi = " << iphi1 << ", ieta " << ieta1 << ", Rdepth " << depth1 << ", Sdepth " << partialMatch << std::endl;
			//std::cout << "Sum: " << En2 << std::endl;
		}

		En2 *= 2;

		//double time1 = (*readRecHitsHF_time1).at(idx1);
		//double time2 = (*readRecHitsHF_time2).at(v2BookMark);	
		
		if(true){ //if(abs(En1 - En2) > enWidth/2){ 
			recHitEnergyHF->Fill(En1,En2);
			recHitEnergyHF2->Fill(En1,En2);
		}

		//if(true){ //if(abs(time1 - time2) > timeWidth/2){
		//	recHitTimingHF->Fill(time1,time2);
		//	recHitTimingHF2->Fill(time1,time2);
		//}
	} //if(rmatched)

    }//Loop over HF

  } //Loop over events

  fout->Write();

}

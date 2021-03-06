{

  gStyle->SetOptStat(0);
  
  TFile *_file0 = TFile::Open("pfstudy_histograms.root");
  TFile *_file1 = TFile::Open("pfstudy_histograms_2019.root");
  _file0->ls();

  // - MC
  TH1F *HcalFrac1Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac1Zero_vs_pt");
  TH1F *HcalFrac2Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac2Zero_vs_pt");
  TH1F *HcalFrac3Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac3Zero_vs_pt");
  TH1F *HcalFrac4Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac4Zero_vs_pt");
  TH1F *HcalFrac5Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac5Zero_vs_pt");
  TH1F *HcalFrac6Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac6Zero_vs_pt");
  TH1F *HcalFrac7Zero    = (TH1F*) _file0->Get("PFTask_hcalFrac7Zero_vs_pt");
  TH1F *HcalFracAllZero  = (TH1F*) _file0->Get("PFTask_hcalFracAllZero_vs_pt");
  
  TH1F *HcalFrac1Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac1Zero_vs_pt");
  TH1F *HcalFrac2Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac2Zero_vs_pt");
  TH1F *HcalFrac3Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac3Zero_vs_pt");
  TH1F *HcalFrac4Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac4Zero_vs_pt");
  TH1F *HcalFrac5Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac5Zero_vs_pt");
  TH1F *HcalFrac6Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac6Zero_vs_pt");
  TH1F *HcalFrac7Zero_2019    = (TH1F*) _file1->Get("PFTask_hcalFrac7Zero_vs_pt");
  TH1F *HcalFracAllZero_2019  = (TH1F*) _file1->Get("PFTask_hcalFracAllZero_vs_pt");
  
  //----------
  
  TCanvas *c5 = new TCanvas("c5","c5",1200,600);
  c5->Divide(4,2);
  gPad->SetLogy();
  gPad->SetGrid(1);

  TH1F *tframe = new TH1F("tframe","tframe",50,-1.5,4.5);
  tframe->SetMinimum(0.);
  tframe->SetMaximum(1.3);
  tframe->SetTitleSize(0.06,"XY");
  tframe->GetYaxis()->SetTitle("Fraction of zero");
  tframe->GetXaxis()->SetTitle("log10(pt (GeV))");
  tframe->GetYaxis()->SetTitleOffset(0.8);
  tframe->GetXaxis()->SetTitleOffset(0.8);
  tframe->SetLabelSize(.04,"XY");

  c5->cd(1);
  gPad->SetGrid();
  tframe->SetTitle("Depth 1");
  tframe->DrawCopy();
  HcalFrac1Zero->Draw("same");
  HcalFrac1Zero_2019->SetLineColor(2);
  HcalFrac1Zero_2019->Draw("same");

  TLegend *tl5 = new TLegend(0.5,0.7,0.9,0.9);
  tl5->AddEntry(HcalFrac1Zero,"t#bar{t} PU 2018");
  tl5->AddEntry(HcalFrac1Zero_2019,"t#bar{t} noPU 2019");
  tl5->Draw();
  
  c5->cd(2);
  gPad->SetGrid();
  tframe->SetTitle("Depth 2");
  tframe->DrawCopy();
  HcalFrac2Zero->Draw("same");
  HcalFrac2Zero_2019->SetLineColor(2);
  HcalFrac2Zero_2019->Draw("same");

  c5->cd(3);
  gPad->SetGrid();
  tframe->SetTitle("Depth 3");
  tframe->DrawCopy();
  HcalFrac3Zero->Draw("same");
  HcalFrac3Zero_2019->SetLineColor(2);
  HcalFrac3Zero_2019->Draw("same");

  c5->cd(4);
  gPad->SetGrid();
  tframe->SetTitle("Depth 4");
  tframe->DrawCopy();
  HcalFrac4Zero->Draw("same");
  HcalFrac4Zero_2019->SetLineColor(2);
  HcalFrac4Zero_2019->Draw("same");

  c5->cd(5);
  gPad->SetGrid();
  tframe->SetTitle("Depth 5");
  tframe->DrawCopy();
  HcalFrac5Zero->Draw("same");
  HcalFrac5Zero_2019->SetLineColor(2);
  HcalFrac5Zero_2019->Draw("same");

  c5->cd(6);
  gPad->SetGrid();
  tframe->SetTitle("Depth 6");
  tframe->DrawCopy();
  HcalFrac6Zero->Draw("same");
  HcalFrac6Zero_2019->SetLineColor(2);
  HcalFrac6Zero_2019->Draw("same");

  c5->cd(7);
  gPad->SetGrid();
  tframe->SetTitle("Depth 7");
  tframe->DrawCopy();
  HcalFrac7Zero->Draw("same");
  HcalFrac7Zero_2019->SetLineColor(2);
  HcalFrac7Zero_2019->Draw("same");

  c5->cd(8);
  gPad->SetGrid();
  tframe->SetTitle("All depth zeros");
  tframe->DrawCopy();
  HcalFracAllZero->Draw("same");
  HcalFracAllZero_2019->SetLineColor(2);
  HcalFracAllZero_2019->Draw("same");
  
  /*
  FC_2p8mm_SiPM->SetLineColor(2);
  FC_2p8mm_SiPM->SetLineStyle(2);
  FC_2p8mm_SiPM->Draw("same");
  TLegend *tl5 = new TLegend(0.7,0.7,0.9,0.9);
  tl5->AddEntry(RawFC_2p8mm_SiPM,"Raw Charge");
  tl5->AddEntry(FC_2p8mm_SiPM,"Pedestal subtracted");
  tl5->Draw();
  */

  c5->Print("plots/plot_PFCand_HcalFracZeros.png");
  c5->Print("plots/plot_PFCand_HcalFracZeros.pdf");
  
  //----------
  
}

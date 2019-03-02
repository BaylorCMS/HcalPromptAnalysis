#------------------------------------------------------------------------------------
# Imports
#------------------------------------------------------------------------------------
import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras
import FWCore.ParameterSet.VarParsing as VarParsing

#------------------------------------------------------------------------------------
# Declare the process and input variables
#------------------------------------------------------------------------------------
#process = cms.Process('NOISE',eras.Run2_50ns)#for 50ns 13 TeV data
#process = cms.Process('NOISE',eras.Run2_25ns)#for 25ns 13 TeV data
options = VarParsing.VarParsing ('analysis')
process = cms.Process("Trees",eras.Run2_2018)

##
## Setup command line options
##
options.register ('skipEvents', 0, VarParsing.VarParsing.multiplicity.singleton, VarParsing.VarParsing.varType.int, "no of skipped events")
options.register ('isMINIAOD', False, VarParsing.VarParsing.multiplicity.singleton, VarParsing.VarParsing.varType.bool, "MINIAODSIM input file(s)?")

##
## Default
##
options.maxEvents = -1 # -1 means all events
#options.skipEvents = 0 # default is 0.

##
## get and parse the command line arguments
##
options.parseArguments()
print("isMINIAOD: ", options.isMINIAOD)
print("maxEvents: ", options.maxEvents)

#
# Dataset e.g.
# dasgoclient --query 'dataset dataset=/RelValTTbar_13/CMSSW_10_2_0_pre3-*realistic*/GEN-SIM-RECO'                 
# dasgoclient --query 'file dataset=/RelValTTbar_13/CMSSW_10_2_0_pre3-101X_upgrade2018_realistic_v7-v1/GEN-SIM-RECO'
#
# TTbar sample
#
# MINIAODSIM
if options.isMINIAOD: 
    options.inputFiles = '/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/MINIAODSIM/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/17E57223-3406-7340-B867-2DDC36E7C371.root'
    options.outputFile = 'relval_ttbar_2018_pmx25ns_miniaodsim.root'
# GEN-SIM-RECO
else:
    #options.inputFiles = '/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/7C1DE9C4-2CDF-6745-9636-A49AF087FDF8.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/571D7C0D-EB5B-AC4B-8D5A-353C2A1E5984.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/EE898FC9-66FA-5044-96D6-82CFC22F847F.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/81CF7193-F950-C44F-A164-94DEF2E788FF.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/0671F9F2-0539-5549-BAFF-1356C29BE98C.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/21369212-DA68-8A41-8176-5D2C6A0E1B12.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/D55D802E-CABC-4747-B288-784330B17B80.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/286A33FA-698B-084B-9521-AB48E9AAA8E8.root','/store/relval/CMSSW_10_3_0_pre4/RelValTTbar_13/GEN-SIM-RECO/PUpmx25ns_103X_upgrade2018_realistic_v4-v1/20000/CC74C106-6A60-4143-8734-1AF16F588FAA.root'
    options.inputFiles = ' /store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-RECO/103X_upgrade2018_realistic_v8_rsb-v1/20000/777544FF-FDFA-D646-BDB6-817029C818D9.root  ',' /store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-RECO/103X_upgrade2018_realistic_v8_rsb-v1/20000/E5574E05-857D-564E-92F2-70632326EDE6.root ', ' /store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-RECO/103X_upgrade2018_realistic_v8_rsb-v1/20000/C242E214-D406-8A41-B4A8-911F960DADB7.root '
    options.secondaryInputFiles = '/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/F0464AF6-54D1-4746-9727-35EA79651016.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/EF56CCB1-2C06-3F4D-9C18-0F6A99682718.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/D0FC064C-B392-3545-B906-0582CE047039.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/96657479-EBDA-2146-90F0-2C47C1B472C6.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/71BC21BC-C71D-AF43-835D-6225DCA13405.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/5037B705-CDCF-1246-B0B3-B3E3B44DCF49.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/43D4DA24-FF21-FB4E-9D5A-C98225B716A9.root ',' /store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/42945BED-63E9-7949-917E-AB04F24C35EF.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/3DBD5CD0-23F7-7A45-91E4-DBF71DAE4C4D.root ','/store/relval/CMSSW_10_4_0_pre4/RelValSinglePiE50HCAL/GEN-SIM-DIGI-RAW/103X_upgrade2018_realistic_v8_rsb-v1/20000/0937D0D4-10C3-D049-A8C8-B673BDB7B291.root '
    options.outputFile = 'relval_SinglePi_2018_E50HCAL_full.root'
#
#
#
#
print("maxEvents: ", options.maxEvents)
print("inputFiles: ", options.inputFiles)
print("outputFile: ", options.outputFile)

#------------------------------------------------------------------------------------
# Get and parse the command line arguments
#------------------------------------------------------------------------------------
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(options.inputFiles),
    secondaryFileNames = cms.untracked.vstring(options.secondaryInputFiles),
    skipEvents = cms.untracked.uint32(options.skipEvents) # default is 0.
)

process.TFileService = cms.Service("TFileService", 
                                   fileName = cms.string(options.outputFile)
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
    Rethrow = cms.untracked.vstring("ProductNotFound"), # make this exception fatal
    fileMode  =  cms.untracked.string('NOMERGE') # no ordering needed, but calls endRun/beginRun etc. at file boundaries
)

#------------------------------------------------------------------------------------
# import of standard configurations
#------------------------------------------------------------------------------------
# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
#process.load('Configuration.StandardSequences.Reconstruction_cff')
#process.load('Configuration.StandardSequences.PATMC_cff')
#process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
process.load('Configuration.StandardSequences.Validation_cff')
process.load('DQMOffline.Configuration.DQMOfflineMC_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#KH
process.MessageLogger.cerr.FwkReport.reportEvery = 100

#------------------------------------------------------------------------------------
# Set up our analyzer
#------------------------------------------------------------------------------------
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_Tree_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_Event_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_GenParticles_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HcalSimHits_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_SimTracks_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HBHERecHits_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HBHEDigis_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HFDigis_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HODigis_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.HcalTupleMaker_HcalTriggerPrimitives_cfi")

process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_PFCandidates_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_PFCluster_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_GenJets_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_GenMet_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_PFJets_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_PFMet_cfi")
process.load("HcalPromptAnalysis.HcalTreeMaker.TupleMaker_PFSimPartilces_cfi")

#------------------------------------------------------------------------------------
# Specify Global Tag
#------------------------------------------------------------------------------------
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase1_2018_realistic', '')

#------------------------------------------------------------------------------------
# HcalTupleMaker sequence definition
#------------------------------------------------------------------------------------
process.tuple_step = cms.Sequence(
    # Make HCAL tuples: Event, run, ls number
    process.hcalTupleEvent*
    # Make HCAL tuples: digi info
    #process.hcalTupleHBHEDigis*
    #process.hcalTupleHODigis*
    #process.hcalTupleHFDigis*
    #process.hcalTupleTriggerPrimitives*
    # Make HCAL tuples: reco info
    process.hcalTupleHBHERecHits*
    # Make HCAL tuples: gen info
    process.hcalTupleGenParticles*
    process.hcalTupleHcalSimHits*
    process.hcalTupleSimTracks*
    #
    #process.tuplePFClusterHGCal*
    #process.tuplePFClusterHGCalFromMultiCL*
    process.tuplePFClusterHO*
    #process.tuplePFClusterHBHE*
    process.tuplePFClusterHF*
    process.tuplePFCandidates*
    process.tuplePFClusterPS*
    process.tuplePFClusterHCAL*
    process.tuplePFClusterECAL*
    process.tuplePFMet*
    process.tuplePFJets*
    process.tupleGenMet*
    process.tupleGenJets*
    process.tuplePFSimParticles*
    #
    process.hcalTupleTree
)

#
# in case we are using MINIAOD files
#
if options.isMINIAOD: 
    process.tuple_step = cms.Sequence(
        # Make HCAL tuples: Event, run, ls number
        process.hcalTupleEvent*
        # Make HCAL tuples: gen info
        #process.hcalTupleGenParticles*
        #
        process.tuplePackedPFCandidates*
        #
        process.hcalTupleTree
    )

#-----------------------------------------------------------------------------------
# Path and EndPath definitions
#-----------------------------------------------------------------------------------
process.preparation = cms.Path(
    process.tuple_step
)
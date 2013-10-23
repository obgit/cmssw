#include "DQMServices/Core/interface/DQMEDAnalyzer.h"

DQMEDAnalyzer::DQMEDAnalyzer() {}

std::shared_ptr<int>
DQMEDAnalyzer::globalBeginRunSummary(edm::Run const&,
                                     edm::EventSetup const&,
                                     RunContext const*)
{
  return 0;
}

void DQMEDAnalyzer::globalEndRunSummary(edm::Run const&,
                                        edm::EventSetup const&,
                                        RunContext const*,
                                        int*)
{}

std::shared_ptr<int>
DQMEDAnalyzer::globalBeginLuminosityBlockSummary(edm::LuminosityBlock const&,
                                                 edm::EventSetup const&,
                                                 LuminosityBlockContext const*)
{
  return 0;
}

void DQMEDAnalyzer::globalEndLuminosityBlockSummary(edm::LuminosityBlock const&,
                                                    edm::EventSetup const&,
                                                    LuminosityBlockContext const*,
                                                    int*)
{}


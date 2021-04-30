//
// Created by tbwsl on 4/28/21.
//

#include "IOData.h"
bool io::IOData::operator==(const io::IOData &rhs) const {
  return mean_rf_dst == rhs.mean_rf_dst &&
         split_score_calc == rhs.split_score_calc &&
         meanModifiedRFDst == rhs.meanModifiedRFDst &&
         taxa_names == rhs.taxa_names &&
         pairwise_distance_mtx == rhs.pairwise_distance_mtx &&
         git_revision == rhs.git_revision &&
         cpuInformation == rhs.cpuInformation;
}
bool io::IOData::operator!=(const io::IOData &rhs) const {
  return !(rhs == *this);
}

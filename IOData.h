#ifndef INFORF_IODATA_H
#define INFORF_IODATA_H
#include "json.hpp"
#include <string>
#include <vector>

namespace io {
struct IOData {
    double mean_rf_dst = 0;
    enum Metric { MCI, MSI, SPI } split_score_calc;
    double                   meanModifiedRFDst = 0;
    std::vector<std::string> taxa_names;
    // Invariant: numEntries = numTaxa - rowID
    std::vector<std::vector<double>> pairwise_distance_mtx;
    std::string                      git_revision;
    std::string                      cpuInformation;

  private:
  public:
    bool operator==(const IOData &rhs) const;
    bool operator!=(const IOData &rhs) const;
};
NLOHMANN_JSON_SERIALIZE_ENUM(IOData::Metric,
                             {{IOData::MCI, "MCI"},
                              {IOData::MSI, "MSI"},
                              {IOData::SPI, "SPI"}});
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(IOData,
                                   mean_rf_dst,
                                   split_score_calc,
                                   meanModifiedRFDst,
                                   taxa_names,
                                   pairwise_distance_mtx,
                                   git_revision,
                                   cpuInformation);
} // namespace io
#endif // INFORF_IODATA_H

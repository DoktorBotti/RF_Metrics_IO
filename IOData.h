#ifndef INFORF_IODATA_H
#define INFORF_IODATA_H
#include <json.hpp>
#include <string>
#include <vector>

namespace io {
struct IOData {
	double mean = 0.;
	enum Metric { MCI, MSI, SPI, RF } metric = Metric::RF;
	enum Measure {SIMILARITY , DISTANCE } measure = Measure::SIMILARITY;
	std::vector<std::string> taxa_names;
	// Invariant: numEntries = numTaxa - rowID
	std::vector<std::vector<double>> pairwise_tree_score;
	std::string git_revision;
	std::string cpuInformation;
	size_t number_of_unique_trees = 0;

	bool operator==(const IOData &rhs) const;
	bool operator!=(const IOData &rhs) const;

	bool compareScoreMatrix(const IOData &other) const;

	static bool parse_raxml(const std::string &overview_file_path,
	                        const std::string &distances_path,
	                        IOData &out);

  private:
	// parsing helpers
	static bool handle_pairwise_dst(size_t major,
	                                size_t minor,
	                                std::ifstream &stream,
	                                std::vector<double> &out);
	static bool parse_pairwise_file(const std::string &distances_path,
	                                size_t num_taxa,
	                                std::vector<std::vector<double>> &res);
	static bool nearly_eq_floating(double a, double b);
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    IOData::Metric,
    {{IOData::MCI, "MCI"}, {IOData::MSI, "MSI"}, {IOData::SPI, "SPI"}, {IOData::RF, "RF"}});

NLOHMANN_JSON_SERIALIZE_ENUM(
    IOData::Measure,
    {{IOData::Measure::DISTANCE, "DISTANCE"}, {IOData::Measure::SIMILARITY, "SIMILARITY"}});
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(IOData,
                                   mean,
                                   metric,
                                   measure,
                                   taxa_names,
                                   pairwise_tree_score,
                                   number_of_unique_trees,
                                   git_revision,
                                   cpuInformation);
} // namespace io
#endif // INFORF_IODATA_H

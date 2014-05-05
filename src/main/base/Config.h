#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <boost/property_tree/ini_parser.hpp>

/**
 * @brief Configuration handler.
 */
class Config
{
private:
    boost::property_tree::ptree pt;

public:
    /**
     * @brief Constructor parses the file and store it in memory.
     * @param filename File name to be parsed;
     */
    Config(const std::string filename) {
        boost::property_tree::read_ini(filename, pt);
    }

    /**
     * @brief Retrieve a configuration by field name.
     * @param field Field name to retrieve.
     */
    template<typename T>
    T get(const std::string field) {
        return pt.get<T>(field);
    }
};

#endif // CONFIG_H

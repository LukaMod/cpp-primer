#ifndef EX_17_03_TEXTQUERY_H_
#define EX_17_03_TEXTQUERY_H_

#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>
#include <tuple>

class TextQuery
{
  public:
    using line_no = std::vector<std::string>::size_type;
    using ret_tuple = std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, std::shared_ptr<std::vector<std::string>>>;

    TextQuery(std::ifstream &);
    ret_tuple query(const std::string &) const;

  private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif
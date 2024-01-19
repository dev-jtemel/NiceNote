/*
 * MIT License
 *
 * Copyright (c) 2024 dev.jtemel@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <fstream>
#include <memory>
#include <regex>
#include <string>

#include "nn/ds/BaseNode.hpp"
#include "nn/parser/DividerParser.hpp"
#include "nn/parser/HeaderParser.hpp"
#include "nn/parser/ImageParser.hpp"

namespace nn {
namespace parser {

/**
 * @brief Read an incoming nnt source file and construct a NiceNote tree from
 * the incoming lines.
 */
class LexicalParser {
 public:
  LexicalParser(const std::string& filename);
  ~LexicalParser();

  /**
   * @brief Parse the file line by line and build the NiceNote tree.
   * @return bool True if no errors are detected.
   */
  bool parse();

 private:
  size_t m_lineNumber{0U};
  std::string m_line{};
  std::string m_content{};

  std::string m_filename{};
  std::ifstream m_stream{};

  std::vector<std::shared_ptr<BaseParser>> m_parsers{
      std::make_shared<HeaderParser>(), std::make_shared<ImageParser>(),
      std::make_shared<DividerParser>()};

  std::vector<std::shared_ptr<ds::BaseNode>> m_nodes{};
};

}  // namespace parser
}  // namespace nn
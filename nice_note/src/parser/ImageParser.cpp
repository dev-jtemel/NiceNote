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

#include "nn/parser/ImageParser.hpp"

#include "nn/ds/node/ImageNode.hpp"

namespace nn {
namespace parser {

ImageParser::ImageParser() : BaseParser(R"(^!\[([^[\]]*)\]\(([^)]*)\)$)") {}

std::shared_ptr<ds::node::BaseNode> ImageParser::attemptParse(
    const std::string& line) {
  if (std::regex_search(line, m_match, m_regex)) {
    return std::make_shared<ds::node::ImageNode>(std::move(m_match[1]),
                                           std::move(m_match[2]));
  }
  return nullptr;
}

}  // namespace parser
}  // namespace nn
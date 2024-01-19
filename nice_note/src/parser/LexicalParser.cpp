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

#include "nn/parser/LexicalParser.hpp"

#include <iostream>
#include <regex>
#include <stdexcept>

#include "nn/ds/HeaderNode.hpp"

namespace nn {
namespace parser {

LexicalParser::LexicalParser(const std::string& filename)
    : m_filename(filename), m_stream(filename) {
  if (!m_stream.is_open()) {
    throw std::runtime_error("Failed to open " + m_filename);
  }
}

LexicalParser::~LexicalParser() {
  m_stream.close();

  for (auto& node : m_nodes) {
    node->toHTML(std::cout);
  }
}

bool LexicalParser::parse() {
  while (std::getline(m_stream, m_line)) {
    ++m_lineNumber;
    std::cerr << "[" << m_lineNumber << "] " << m_line << std::endl;

    std::shared_ptr<ds::BaseNode> node{nullptr};
    for (auto& parser : m_parsers) {
      node = parser->attemptParse(m_line);
      if (node) {
        m_nodes.emplace_back(node);
        continue;
      }
    }
  }

  return true;
}

}  // namespace parser
}  // namespace nn
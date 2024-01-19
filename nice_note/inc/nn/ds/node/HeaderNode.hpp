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

#ifndef NN__DS__HEADER_NODE_HPP
#define NN__DS__HEADER_NODE_HPP

#include <iostream>
#include <string>

#include "nn/ds/node/BaseNode.hpp"

namespace nn {
namespace ds {
namespace node {

/**
 * @brief Represents a heading from level 1 - 6.
 *
 * Example:
 *  <h1>1</h1>
 *  <h2>2</h2
 *  <h3>3</h3>
 *  <h4>4</h4>
 *  <h5>5</h5>
 *  <h6>6</h6>
 */
struct HeaderNode : public BaseNode {
  HeaderNode(size_t tier, std::string&& content_)
      : BaseNode("h"), content{content_} {
    token.append(std::to_string(tier));
  }

  std::ostream& toHTML(std::ostream& stream) override {
    return stream << "<" << token << ">" << content << "</" << token << ">"
                  << std::endl;
  }

  std::string content{};
};

}  // namespace node
}  // namespace ds
}  // namespace nn

#endif  // NN__DS__HEADER_NODE_HPP
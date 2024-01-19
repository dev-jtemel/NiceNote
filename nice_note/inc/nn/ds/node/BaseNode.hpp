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

#ifndef NN__DS__BASE_NODE_HPP
#define NN__DS__BASE_NODE_HPP

#include <ostream>
#include <regex>
#include <string>

namespace nn {
namespace ds {
namespace node {

/**
 * @brief Abstract class for representing a node in the NiceNote tree.
 */
struct BaseNode {
  BaseNode() = default;
  BaseNode(std::string&& token_) : token(token_) {}
  virtual ~BaseNode() {}

  virtual void appendContent(std::string&&) {}

  /**
   * @brief Dump the contents of this node in HTML compliant format.
   */
  virtual std::ostream& toHTML(std::ostream& stream) = 0;

  std::string token{};
};

}  // namespace node
}  // namespace ds
}  // namespace nn

#endif  // NN__DS__BASE_NODE_HPP
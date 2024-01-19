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

#ifndef NN__DS__NNTREE_HPP
#define NN__DS__NNTREE_HPP

#include <iostream>

#include "nn/ds/node/BaseNode.hpp"

namespace nn {
namespace ds {

/**
 * @brief Stores a AST that is constructed from the given NiceNoteText source
 * file.
 */
class NNTree {
 public:
  NNTree() = default;
  ~NNTree() = default;

  bool insertNode(std::shared_ptr<node::BaseNode>& node) {
    if (!m_head) {
      m_head = node;
      m_current = node;
      return true;
    }

    m_current->next = node;
    m_current = m_current->next;
    return true;
  }

  std::shared_ptr<node::BaseNode> popNode() {
    if (!m_head) {
      return nullptr;
    }

    auto oldHead = m_head;
    m_head = m_head->next;
    return oldHead;
  }

 private:
  std::shared_ptr<node::BaseNode> m_head{nullptr};
  std::shared_ptr<node::BaseNode> m_current{nullptr};
};

}  // namespace ds
}  // namespace nn

#endif  // NN__DS__NNTREE_HPP
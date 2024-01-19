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

#include "nn/ds/NNTree.hpp"

namespace nn {
namespace ds {

void NNTree::insertNode(std::shared_ptr<node::BaseNode>& node) {
  if (!m_head) {
    m_head = node;
    m_current = node;
    return;
  }

  m_current->next = node;
  m_current = m_current->next;
}

std::shared_ptr<node::BaseNode> NNTree::popNode() {
  if (!m_head) {
    return nullptr;
  }

  auto oldHead = m_head;
  m_head = m_head->next;
  return oldHead;
}

void NNTree::dump() const {
  auto head = m_head;
  while (head) {
    head->dump(std::cerr);
    head = head->next;
  }
}

}  // namespace ds
}  // namespace nn
/*
 * Tencent is pleased to support the open source community by making wwsearch
 * available.
 *
 * Copyright (C) 2018-present Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#include "prefix_query.h"
#include "prefix_weight.h"

namespace wwsearch {

PrefixQuery::PrefixQuery(FieldID field_id, const std::string &term,
                         uint32_t max_doc_list_size)
    : field_id_(field_id),
      match_term_(term),
      max_doc_list_size_(max_doc_list_size) {}

PrefixQuery::~PrefixQuery() {}

Weight *PrefixQuery::CreateWeight(SearchContext *context, bool needs_scores,
                                  double boost) {
  return new PrefixWeight(this);
}

}  // namespace wwsearch

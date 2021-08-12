/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "cachelib/navy/block_cache/Index.h"
#include "cachelib/navy/common/Hash.h"
#include "cachelib/navy/common/Types.h"
#include "cachelib/navy/serialization/Serialization.h"

namespace facebook {
namespace cachelib {
namespace navy {
// Abstract base class of a reinsertion policy.
class ReinsertionPolicy {
 public:
  virtual ~ReinsertionPolicy() = default;

  // Passes in the index.
  virtual void setIndex(Index* index) = 0;

  // Determines whether or not we should keep this key around longer in cache.
  virtual bool shouldReinsert(HashedKey hk) = 0;

  // Persists metadata associated with this policy.
  virtual void persist(RecordWriter& rw) = 0;

  // Recovers from previously persisted metadata associated with this policy.
  virtual void recover(RecordReader& rr) = 0;

  // Exports policy stats via CounterVisitor.
  virtual void getCounters(const CounterVisitor& visitor) const = 0;
};
} // namespace navy
} // namespace cachelib
} // namespace facebook

/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FactoryRenewer_hpp
#define FactoryRenewer_hpp

#include <WCDB/Assembler.hpp>
#include <WCDB/ErrorProne.hpp>
#include <WCDB/FactoryRelated.hpp>

namespace WCDB {

namespace Repair {

class FactoryRenewer : public FactoryRelated, public ErrorProne {
public:
    FactoryRenewer(Factory &factory);
    const std::string directory;
    const std::string database;

    bool prepare();
    bool work();

protected:
    bool resolveSequencesForDatabase(
        std::map<std::string, int64_t> &resolvedSequences,
        const std::string &databaseForAcquisition);
    bool assembleSequences(const std::map<std::string, int64_t> &sequences);

#pragma mark - Assembler
public:
    void setAssembler(const std::shared_ptr<Assembler> &assembler);

protected:
    std::shared_ptr<Assembler> m_assembler;
};

} //namespace Repair

} //namespace WCDB

#endif /* FactoryRenewer_hpp */

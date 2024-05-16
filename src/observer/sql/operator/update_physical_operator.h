#pragma once

#include "sql/operator/physical_operator.h"
//#include "src/observer/storage/trx/vacuous_trx.h"

class UpdateStmt;

/**
 * @brief 物理算子
 * @ingroup PhysicalOperator
 */
class UpdatePhysicalOperator : public PhysicalOperator
{
  public:
    UpdatePhysicalOperator(Table* table, Field field, Value value);
    virtual ~UpdatePhysicalOperator()=default;

    PhysicalOperatorType type() const override
    {
        return PhysicalOperatorType::INSERT;
    }

    RC open(Trx* trx) override;
    RC next() override;
    RC close() override;

    Tuple* current_tuple() override { return nullptr; }

  private:
    Table* table_ = nullptr;
    Value  value_;
    Field  field_;
    Trx*   trx_        = nullptr;
};
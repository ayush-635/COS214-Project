#ifndef CONCRETESPACEBUILDER_H
#define CONCRETESPACEBUILDER_H
#include "../SpaceBuilder/SpaceBuilder.h"
#include "../PlanterBox/PlanterBox.h"

class ConcreteSpaceBuilder : public SpaceBuilder {
public:
    ConcreteSpaceBuilder();
    void addPlanterBox() override;
    void addSubCollection() override;
    void addDefault();
    PlantableArea* build();
};

#endif

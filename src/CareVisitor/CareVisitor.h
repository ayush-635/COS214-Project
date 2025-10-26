#ifndef CAREVISITOR_H
#define CAREVISITOR_H

// Forward declarations
class FlowerPlant;
class TreePlant;
class HerbPlant;
class GrassPlant;
class SucculentPlant;

class CareVisitor {
public:
    virtual ~CareVisitor() = default;
    
    // Abstract visit methods for all plant types
    virtual void visitFlowerPlant(FlowerPlant* flower) = 0;
    virtual void visitTreePlant(TreePlant* tree) = 0;
    virtual void visitHerbPlant(HerbPlant* herb) = 0;
    virtual void visitGrassPlant(GrassPlant* grass) = 0;
    virtual void visitSucculentPlant(SucculentPlant* succulent) = 0;
};

#endif
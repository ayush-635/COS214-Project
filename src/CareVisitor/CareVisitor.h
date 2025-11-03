#ifndef CAREVISITOR_H
#define CAREVISITOR_H

class FlowerPlant;
class TreePlant;
class HerbPlant;
class GrassPlant;
class SucculentPlant;

/**
 * @class CareVisitor
 * @brief Abstract visitor interface for plant care operations
 * 
 * Implements the Visitor pattern to perform type-specific operations
 * on different plant types without modifying the plant classes themselves.
 */
class CareVisitor {
public:
    virtual ~CareVisitor() = default;

    /**
     * @brief Visit a FlowerPlant for care operations
     * @param flower The flower plant to visit
     */
    virtual void visitFlowerPlant(FlowerPlant* flower) = 0;
    /**
     * @brief Visit a TreePlant for care operations
     * @param tree The tree plant to visit
     */
    virtual void visitTreePlant(TreePlant* tree) = 0;
    /**
     * @brief Visit a HerbPlant for care operations
     * @param herb The herb plant to visit
     */
    virtual void visitHerbPlant(HerbPlant* herb) = 0;
    /**
     * @brief Visit a GrassPlant for care operations
     * @param grass The grass plant to visit
     */
    virtual void visitGrassPlant(GrassPlant* grass) = 0;
    /**
     * @brief Visit a SucculentPlant for care operations
     * @param succulent The succulent plant to visit
     */
    virtual void visitSucculentPlant(SucculentPlant* succulent) = 0;
};

#endif
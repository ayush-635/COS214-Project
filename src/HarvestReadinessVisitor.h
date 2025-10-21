#ifndef HARVESTREADINESSVISITOR_H
#define HARVESTREADINESSVISITOR_H

class HarvestReadinessVisitor : CareVisitor {


public:
	void visitFlower(Flower* plant);

	void visitCactus(Cactus* cactus);

	void visitTree(Tree* tree);

	void visitHerb(Herb* herb);

	void visitGrass(Grass* grass);

	vector<Plant2*> getReadyPlants();

	void clearReadyPlants();
};

#endif

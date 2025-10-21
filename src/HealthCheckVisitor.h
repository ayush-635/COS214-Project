#ifndef HEALTHCHECKVISITOR_H
#define HEALTHCHECKVISITOR_H

class HealthCheckVisitor : CareVisitor {


public:
	void visitFlower(Flower* plant);

	void visitCactus(Cactus* cactus);

	void visitTree(Tree* tree);

	void visitHerb(Herb* herb);

	void visitGrass(Grass* grass);

	void printReports();

	void clearReports();
};

#endif

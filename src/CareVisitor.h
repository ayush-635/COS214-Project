#ifndef CAREVISITOR_H
#define CAREVISITOR_H

class CareVisitor {


public:
	void visitFlower(Flower* plant);

	void visitCactus(Cactus* cactus);

	void visitTree(Tree* tree);

	void visitHerb(Herb* herb);

	void visitGrass(Grass* grass);

	CareVisitor();
};

#endif

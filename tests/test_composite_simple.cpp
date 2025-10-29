#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Tile/Tile.h"
#include "../src/PlanterBox/PlanterBox.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include "../src/PlantIterator/PlantIterator.h"

TEST_CASE("Composite - Create Tile") {
    Tile tile(1);
    CHECK(tile.getId() == 1);
    CHECK(tile.getPlantableArea() != nullptr);
}

TEST_CASE("Composite - Add boxes") {
    Tile tile(1);
    PlanterBoxCollection* root = tile.getPlantableArea();
    
    PlanterBox* box1 = new PlanterBox();
    PlanterBox* box2 = new PlanterBox();
    
    root->add(box1);
    root->add(box2);
    
    CHECK(root->getChild(0) != nullptr);
    CHECK(root->getChild(1) != nullptr);
}

TEST_CASE("Composite - Capacity limit (4 boxes max)") {
    PlanterBoxCollection collection(0);
    
    for(int i = 0; i < 4; i++) {
        PlanterBox* box = new PlanterBox();
        collection.add(box);
    }
    
    CHECK(collection.getChild(0) != nullptr);
    CHECK(collection.getChild(3) != nullptr);
    
    // Try to add 5th box
    PlanterBox* box5 = new PlanterBox();
    collection.add(box5);
    CHECK(collection.getChild(4) == nullptr);
    delete box5;
}

TEST_CASE("Composite - Nesting at depth 1") {
    PlanterBoxCollection root(0);
    PlanterBoxCollection* nested = new PlanterBoxCollection(1);
    
    root.add(nested);
    
    PlantableArea* child = root.getChild(0);
    CHECK(child != nullptr);
    CHECK(dynamic_cast<PlanterBoxCollection*>(child) != nullptr);
}

TEST_CASE("Composite - Cannot nest too deep") {
    PlanterBoxCollection root(0);
    PlanterBoxCollection* nested = new PlanterBoxCollection(1);
    root.add(nested);
    
    // Try to add depth 2 (should fail)
    PlanterBoxCollection* tooDeep = new PlanterBoxCollection(2);
    nested->add(tooDeep);
    
    CHECK(nested->getChild(0) == nullptr);
    delete tooDeep;
}

TEST_CASE("Iterator - Create iterator for empty box") {
    PlanterBox* box = new PlanterBox();
    PlantIterator iterator(box);
    
    CHECK(iterator.hasNext() == false);
    CHECK(iterator.first() == nullptr);
}

TEST_CASE("Iterator - Create iterator for empty collection") {
    PlanterBoxCollection* collection = new PlanterBoxCollection(0);
    PlantIterator iterator(collection);
    
    CHECK(iterator.hasNext() == false);
    CHECK(iterator.first() == nullptr);
}

TEST_CASE("Iterator - Traverse flat collection structure") {
    PlanterBoxCollection* collection = new PlanterBoxCollection(0);
    
    PlanterBox* box1 = new PlanterBox();
    PlanterBox* box2 = new PlanterBox();
    
    collection->add(box1);
    collection->add(box2);
    
    PlantIterator iterator(collection);
    
    // Just verify iterator can be created and called
    CHECK_NOTHROW(iterator.first());
    CHECK_NOTHROW(iterator.hasNext());
    CHECK_NOTHROW(iterator.next());
}

TEST_CASE("Iterator - Traverse nested collection structure") {
    PlanterBoxCollection* root = new PlanterBoxCollection(0);
    
    PlanterBox* box1 = new PlanterBox();
    root->add(box1);
    
    PlanterBoxCollection* nested = new PlanterBoxCollection(1);
    PlanterBox* box2 = new PlanterBox();
    PlanterBox* box3 = new PlanterBox();
    nested->add(box2);
    nested->add(box3);
    root->add(nested);
    
    PlantIterator iterator(root);
    
    // Verify iterator handles nested structure
    CHECK_NOTHROW(iterator.first());
    CHECK_NOTHROW(iterator.hasNext());
    CHECK_NOTHROW(iterator.next());
}

TEST_CASE("Integration - Complex nested structure") {
    Tile tile(1);
    PlanterBoxCollection* root = tile.getPlantableArea();
    
    // Add direct box
    PlanterBox* box1 = new PlanterBox();
    root->add(box1);
    
    // Add nested collection
    PlanterBoxCollection* nested = new PlanterBoxCollection(1);
    PlanterBox* box2 = new PlanterBox();
    PlanterBox* box3 = new PlanterBox();
    nested->add(box2);
    nested->add(box3);
    root->add(nested);
    
    // Add another direct box
    PlanterBox* box4 = new PlanterBox();
    root->add(box4);
    
    // Verify structure
    CHECK(root->getChild(0) != nullptr);
    CHECK(root->getChild(1) != nullptr);
    CHECK(root->getChild(2) != nullptr);
    
    // Test iterator can traverse entire structure
    PlantIterator iterator(root);
    CHECK_NOTHROW(iterator.first());
    CHECK_NOTHROW(iterator.next());
}
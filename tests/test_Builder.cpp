#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/SpaceBuilder/SpaceBuilder.h"
#include "../src/ConcreteSpaceBuilder/ConcreteSpaceBuilder.h"
#include "../src/NurseryManager/NurseryManager.h"
#include "../src/PlanterBox/PlanterBox.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include "../src/PlantableArea/PlantableArea.h"

TEST_SUITE("Builder Pattern Tests") {
    
    TEST_CASE("ConcreteSpaceBuilder - Initialization") {
        ConcreteSpaceBuilder builder;
        
        SUBCASE("Builder starts with null space") {
            CHECK(builder.getSpace() == nullptr);
        }
        
        SUBCASE("createNewSpace creates root collection") {
            builder.createNewSpace();
            CHECK(builder.getSpace() != nullptr);
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            CHECK(collection != nullptr);
            CHECK(collection->getDepth() == 0);
        }
    }
    
    TEST_CASE("ConcreteSpaceBuilder - Adding Single Components") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        
        SUBCASE("Add single planter box") {
            builder.addPlanterBox();
            
            PlantableArea* space = builder.getSpace();
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
            
            CHECK(collection != nullptr);
            CHECK(collection->getChild(0) != nullptr);
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(collection->getChild(0));
            CHECK(box != nullptr);
        }
        
        SUBCASE("Add multiple planter boxes") {
            builder.addPlanterBox();
            builder.addPlanterBox();
            builder.addPlanterBox();
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
        }
        
        SUBCASE("Add maximum planter boxes (4)") {
            builder.addPlanterBox();
            builder.addPlanterBox();
            builder.addPlanterBox();
            builder.addPlanterBox();
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
            CHECK(collection->getChild(3) != nullptr);
        }
    }
    
    TEST_CASE("ConcreteSpaceBuilder - Default Components") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        
        SUBCASE("addDefault adds 2 boxes") {
            builder.addDefault();
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
        }
        
        SUBCASE("Can add more boxes after default") {
            builder.addDefault();
            builder.addPlanterBox();
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
        }
    }
    
    TEST_CASE("ConcreteSpaceBuilder - Nested Collections") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        
        SUBCASE("Add single sub-collection") {
            builder.addSubCollection();
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            CHECK(root != nullptr);
            
            PlantableArea* child = root->getChild(0);
            CHECK(child != nullptr);
            
            PlanterBoxCollection* nested = dynamic_cast<PlanterBoxCollection*>(child);
            CHECK(nested != nullptr);
            CHECK(nested->getDepth() == 1);
        }
        
        SUBCASE("Sub-collection depth is parent depth + 1") {
            builder.addSubCollection();
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            PlanterBoxCollection* nested = dynamic_cast<PlanterBoxCollection*>(root->getChild(0));
            
            CHECK(root->getDepth() == 0);
            CHECK(nested->getDepth() == 1);
        }
        
        SUBCASE("Cannot nest beyond max depth") {
            builder.addSubCollection();
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            PlanterBoxCollection* nested = dynamic_cast<PlanterBoxCollection*>(root->getChild(0));
            
            PlanterBoxCollection* tooDeep = new PlanterBoxCollection(2);
            nested->add(tooDeep);
            
            CHECK(nested->getChild(0) == nullptr);
            delete tooDeep;
        }
    }
    
    TEST_CASE("ConcreteSpaceBuilder - Mixed Components") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        
        SUBCASE("Mix boxes and collections") {
            builder.addPlanterBox();
            builder.addSubCollection();
            builder.addPlanterBox();
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(root->getChild(0) != nullptr);
            CHECK(root->getChild(1) != nullptr);
            CHECK(root->getChild(2) != nullptr);
            
            PlanterBox* box1 = dynamic_cast<PlanterBox*>(root->getChild(0));
            PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(root->getChild(1));
            PlanterBox* box2 = dynamic_cast<PlanterBox*>(root->getChild(2));
            
            CHECK(box1 != nullptr);
            CHECK(coll != nullptr);
            CHECK(box2 != nullptr);
        }
        
        SUBCASE("Complex nested structure") {
            builder.addPlanterBox();
            builder.addSubCollection();
            builder.addPlanterBox();
            builder.addSubCollection();
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            CHECK(root->getChild(0) != nullptr);
            CHECK(root->getChild(1) != nullptr);
            CHECK(root->getChild(2) != nullptr);
            CHECK(root->getChild(3) != nullptr);
        }
    }
    
    TEST_CASE("ConcreteSpaceBuilder - Build Method") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        builder.addPlanterBox();
        builder.addPlanterBox();
        
        SUBCASE("Build returns constructed space") {
            PlantableArea* result = builder.build();
            CHECK(result != nullptr);
        }
        
        SUBCASE("Build resets internal space to nullptr") {
            PlantableArea* result = builder.build();
            CHECK(builder.getSpace() == nullptr);
        }
        
        SUBCASE("Can build multiple spaces sequentially") {
            PlantableArea* space1 = builder.build();
            
            builder.createNewSpace();
            builder.addPlanterBox();
            PlantableArea* space2 = builder.build();
            
            CHECK(space1 != space2);
            CHECK(space1 != nullptr);
            CHECK(space2 != nullptr);
        }
        
        SUBCASE("Built space retains structure") {
            builder.addPlanterBox();
            PlantableArea* result = builder.build();
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(result);
            CHECK(collection != nullptr);
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
        }
    }
    
    TEST_CASE("NurseryManager - Director Pattern") {
        NurseryManager manager;
        ConcreteSpaceBuilder builder;
        manager.setBuilder(&builder);
        
        SUBCASE("Construct small space (2 boxes)") {
            PlantableArea* space = manager.constructSmallSpace();
            CHECK(space != nullptr);
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
            CHECK(collection != nullptr);
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
        }
        
        SUBCASE("Construct medium space (4 boxes)") {
            PlantableArea* space = manager.constructMediumSpace();
            CHECK(space != nullptr);
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
            CHECK(collection != nullptr);
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
            CHECK(collection->getChild(3) != nullptr);
        }
        
        SUBCASE("Construct big space (nested structure)") {
            PlantableArea* space = manager.constructBigSpace();
            CHECK(space != nullptr);
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
            CHECK(collection != nullptr);
            
            PlantableArea* firstChild = collection->getChild(0);
            CHECK(firstChild != nullptr);
            
            PlanterBoxCollection* nested = dynamic_cast<PlanterBoxCollection*>(firstChild);
            CHECK(nested != nullptr);
            CHECK(nested->getDepth() == 1);
        }
        
        SUBCASE("Big space has correct number of children") {
            PlantableArea* space = manager.constructBigSpace();
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
            
            CHECK(collection->getChild(0) != nullptr);
            CHECK(collection->getChild(1) != nullptr);
            CHECK(collection->getChild(2) != nullptr);
            CHECK(collection->getChild(3) != nullptr);
        }
    }
    
    TEST_CASE("NurseryManager - Multiple Space Construction") {
        NurseryManager manager;
        ConcreteSpaceBuilder builder;
        manager.setBuilder(&builder);
        
        SUBCASE("Build multiple small spaces") {
            PlantableArea* space1 = manager.constructSmallSpace();
            PlantableArea* space2 = manager.constructSmallSpace();
            
            CHECK(space1 != nullptr);
            CHECK(space2 != nullptr);
            CHECK(space1 != space2);
        }
        
        SUBCASE("Build different space types sequentially") {
            PlantableArea* small = manager.constructSmallSpace();
            PlantableArea* medium = manager.constructMediumSpace();
            PlantableArea* big = manager.constructBigSpace();
            
            CHECK(small != nullptr);
            CHECK(medium != nullptr);
            CHECK(big != nullptr);
            
            CHECK(small != medium);
            CHECK(medium != big);
            CHECK(small != big);
        }
    }
    
    TEST_CASE("Builder Pattern - Manual Construction") {
        ConcreteSpaceBuilder builder;
        
        SUBCASE("Build custom configuration without director") {
            builder.createNewSpace();
            builder.addPlanterBox();
            builder.addSubCollection();
            builder.addPlanterBox();
            builder.addPlanterBox();
            
            PlantableArea* customSpace = builder.build();
            CHECK(customSpace != nullptr);
            
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(customSpace);
            CHECK(root->getChild(0) != nullptr);
            CHECK(root->getChild(1) != nullptr);
            CHECK(root->getChild(2) != nullptr);
            CHECK(root->getChild(3) != nullptr);
        }
        
        SUBCASE("Build only nested collections") {
            builder.createNewSpace();
            builder.addSubCollection();
            builder.addSubCollection();
            
            PlantableArea* space = builder.build();
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(space);
            
            CHECK(root->getChild(0) != nullptr);
            CHECK(root->getChild(1) != nullptr);
            
            PlanterBoxCollection* nested1 = dynamic_cast<PlanterBoxCollection*>(root->getChild(0));
            PlanterBoxCollection* nested2 = dynamic_cast<PlanterBoxCollection*>(root->getChild(1));
            
            CHECK(nested1 != nullptr);
            CHECK(nested2 != nullptr);
        }
    }
    
    TEST_CASE("Builder Error Handling") {
        ConcreteSpaceBuilder builder;
        
        SUBCASE("Adding components before createNewSpace") {
            CHECK_NOTHROW(builder.addPlanterBox());
            CHECK_NOTHROW(builder.addSubCollection());
            CHECK_NOTHROW(builder.addDefault());
        }
        
        SUBCASE("Building without creating space returns nullptr") {
            PlantableArea* result = builder.build();
            CHECK(result == nullptr);
        }
        
        SUBCASE("Building empty space") {
            builder.createNewSpace();
            PlantableArea* result = builder.build();
            
            CHECK(result != nullptr);
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(result);
            CHECK(collection != nullptr);
            CHECK(collection->getChild(0) == nullptr);
        }
    }
    
    TEST_CASE("Builder Pattern - Depth Constraints") {
        ConcreteSpaceBuilder builder;
        builder.createNewSpace();
        
        SUBCASE("Root collection is depth 0") {
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            CHECK(root->getDepth() == 0);
        }
        
        SUBCASE("Sub-collection is depth 1") {
            builder.addSubCollection();
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            PlanterBoxCollection* nested = dynamic_cast<PlanterBoxCollection*>(root->getChild(0));
            
            CHECK(nested->getDepth() == 1);
        }
        
        SUBCASE("Cannot add collection at wrong depth") {
            PlanterBoxCollection* root = dynamic_cast<PlanterBoxCollection*>(builder.getSpace());
            
            PlanterBoxCollection* wrongDepth = new PlanterBoxCollection(5);
            root->add(wrongDepth);
            
            CHECK(root->getChild(0) == nullptr);
            delete wrongDepth;
        }
    }
}

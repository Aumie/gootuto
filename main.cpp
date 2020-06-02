#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
/*TEST(bobotest, subobo){
    ASSERT_EQ( 1,1);
    EXPECT_EQ(1,1);
    ASSERT_FALSE( 1==1);
}
TEST(bobootest, suboboo){
    int val = 1;

    val +=6;

    ASSERT_EQ(val,7);
}
class MyClass{
    std::string id;
public:
    MyClass(std::string _id) : id(_id){}
    std::string GetId(){return id;}
};

TEST(Myclassss,increase){
    MyClass mc("root");

    std::string value = mc.GetId();

    EXPECT_STREQ(value.c_str(),"root");
}*/
class MClass{
    int baseVal;
public:
    MClass(int _bv) : baseVal(_bv){}
    void Increment(int byValue){
        baseVal += byValue;
    }
    int getValue(){return baseVal;}
};
TEST(ClassTest, Incrementby5){
    MClass mc(100);

    mc.Increment(5);

    ASSERT_EQ(mc.getValue(),105);
}
struct MyclassTest: public testing::Test{
    MClass *mct;
    void SetUp(){std::cout<<"Alive\n";mct = new MClass(100);}
    void TearDown(){std::cout<<"Dead";delete mct;}
};
TEST_F(MyclassTest, Incrementby10){
    mct->Increment(10);
    std::cout<< "Test_F\n";
    ASSERT_EQ(mct->getValue(),110);
}

class Stack{
    std::vector<int> vstack ={};
public:
    void push(int value){vstack.push_back(value);}
    int pop(){
        if(!vstack.empty()) {
            int value = vstack.back();
            vstack.pop_back();
            return value;
        } else{
            return -1;
        }
    }
    int size() { return vstack.size(); }

};
struct stackTest : public testing::Test{
    Stack sl;
    void SetUp(){
        int value[] = {1,2,3,4,5,6};
        for(auto &val : value){
            sl.push(val);
        }
    };
    void TearDown(){

    };
};
TEST_F(stackTest, PopTest){
    int lastPoppedValue = 6;
    while(lastPoppedValue != 1){
        ASSERT_EQ(sl.pop(), lastPoppedValue--);
    }
}
TEST_F(stackTest, sizeValidate){
    int val = sl.size();
    for(val;!val;val--){
        //ASSERT_EQ(sl.pop(), val);
        ASSERT_NE(sl.pop(),-1);
    }
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

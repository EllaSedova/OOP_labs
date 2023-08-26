#pragma once
#include "Field.h"


//template<typename...Rules>
//class FieldGenerator {
//public:
//    Field *field = new Field(10,10);
//    Field *generate(Rules... rule) {
//        (rule.fill(field),...);
//        return field;
//    }
//};



template<typename ... Rules>
class FieldGenerator {
public:
    Field *field = new Field(10,10);
    Field * generate(){
        (CreateRule<Rules>(field), ...);
        return field;
    }

    template<typename Rule>
    void CreateRule(Field * field)
        {
            Rule rule;
            rule.fill(field);
        }
};

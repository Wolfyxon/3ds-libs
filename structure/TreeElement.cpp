#include "TreeElement.h"

vector<TreeElement*> TreeElement::getChildren(){
    return children;
}

vector<TreeElement*> TreeElement::getDescendants(){
    vector<TreeElement*> res;
    for(size_t i=0; i<children.size(); i++){
        TreeElement* child = children[i];
        res.push_back(child);
        vector<TreeElement*> sub = child->getDescendants();
        for(size_t ii=0; i<sub.size(); ii++){
            res.push_back(sub[i]);
        }
    }
    return res;
}

vector<TreeElement*> TreeElement::getAncestors(){
    vector<TreeElement*> res;
    TreeElement* current = this;
    while (current->parent != NULL){
        current = current->parent;
        res.push_back(current);
    }
    return res;
}

void TreeElement::addChild(TreeElement* child){
    if(child->parent == this) return;

    child->parent = this;
    children.push_back(child);
}

void TreeElement::removeChild(TreeElement* child){
    if(!hasChild(child)) return;
    size_t idx = getChildIdx(child);
    if(idx == -1) return;
    vector<TreeElement*>::iterator it = children.begin();
    std::advance(it, idx);
    children.erase(it);
    child->parent = NULL;
}

size_t TreeElement::getChildIdx(TreeElement* child){
    for(size_t i=0; i<children.size(); i++){
        if(children[i] == child) return i;
    }
    return -1;
}

bool TreeElement::hasChild(TreeElement* child){
    return (
        child->parent == this && 
        (std::find(children.begin(), children.end(), child) != children.end()) 
    );
}
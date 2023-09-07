#pragma once
#include <vector>
#include <algorithm> 

using namespace std;

class TreeElement {
    public:
        TreeElement();
        ~TreeElement();

        /** Returns pointers to the children TreeElements */
        vector<TreeElement*> getChildren();
        /** Returns pointers to all descendant TreeElements (children, children of children, and so on...)*/
        vector<TreeElement*> getDescendants();
        /** Returns pointers to all ancestor TreeElements (parent, parent of parent, and so on...)*/
        vector<TreeElement*> getAncestors();
        /** Deletes the TreeElement */
        void free();
        /**
         * Removes a child.
         * @param child Pointer to child TreeElement.
        */
       void removeChild(TreeElement* child);
       /**
        * Returns index of a child. Returns -1 if the child is not found.
        * @param child Pointer to child TreeElement.
       */
        int getChildIdx(TreeElement* child);
        /**
         * Adds another TreeElement as a child.
         * @param element Pointer to the TreeElement you want to add.
        */
       void addChild(TreeElement* child);
        /**
         * Checks if the current element is the parent of a child.
         * @param child Pointer to child TreeElement.
        */
       bool hasChild(TreeElement* child);
        /**
         * Returns pointer to the child TreeElement at the specified index. Returns NULL if the child is not found.
         * @param index Index of the child.
        */
       TreeElement* getNthChild(size_t index);
        /** Returns pointer to the parent TreeElement or NULL if this TreeElement is an orphan. */
       TreeElement* getParent();
    private:
        vector<TreeElement*> children;
        TreeElement* parent;
};
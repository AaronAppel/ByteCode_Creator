#ifndef _Compiler_H_
#define _Compiler_H_

#include "InstructionBlock.h"
#include <string>

class InstructionBlock;

class Compiler
{
public:
    Compiler();
    ~Compiler();
    
    void GenerateItem(Item* item);
    void GenerateCharacter(Character* item);

private:
    InstructionBlock* m_Block = nullptr;
};

Compiler::Compiler()
{
    m_Block = new InstructionBlock(20); // TODO: Choose a better starting size
}

Compiler::~Compiler()
{
    delete m_Block;
}

void Compiler::GenerateItem(Item* item)
{
    // fill instruction block with item data
    m_Block->PushBack((char)Inst_Literal);
    m_Block->PushBack((char)(item->GetCost())); // cost
    m_Block->PushBack((char)Inst_Value);
    m_Block->PushBack((char)IStat_Cost);

    m_Block->PushBack((char)Inst_Stop); // null terminator

    // write item data to name.item
    std::string fileName = "Data/Items/" + item->GetName() + ".item"; // name file item->name.item
    WriteRawBytesToFile(fileName.c_str(), (char*)m_Block->DataStart(), m_Block->GetEffectiveSize());
}

void Compiler::GenerateCharacter(Character* c)
{
    // fill instruction block with item data
    m_Block->PushBack((char)Inst_Literal);
    m_Block->PushBack((char)(c->GetMaxEnergy())); // cost
    m_Block->PushBack((char)Inst_Value);
    m_Block->PushBack((char)Char_Energy);

    m_Block->PushBack((char)Inst_Stop); // null terminator

    // write item data to name.item
    std::string fileName = "Data/Characters/" + c->GetName() + ".char"; // name file character->name.item
    WriteRawBytesToFile(fileName.c_str(), (char*)m_Block->DataStart(), m_Block->GetEffectiveSize());
}

#endif // _Compiler_H_
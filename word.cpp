#include "word.h"
#include "game.h"
#include <QColor>
#include <QFont>

Word::Word(QString word, QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    this->word = word;
    setTextWidth(200);
    setHtml("<center>"+word+"</center>");
    setFont(QFont(QString("Courier New")));
    setDefaultTextColor(QColor(Qt::gray));
}

void Word::RemoveFirstCharacter()
{
    word.remove(0,1);
}

void Word::VisualRemoveFirstCharacter()
{
    setHtml("<center>"+toPlainText().remove(0,1)+"</center>");
}

void Word::UpdateWord()
{
    setHtml("<center>"+word+"</center>");
}

#include "word.h"
#include "game.h"
#include <QColor>
#include <QFont>

Word::Word(QString word, QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    this->word = word;
    setPlainText(word);
    setDefaultTextColor(QColor(Qt::gray));
}

#ifndef WORD_H
#define WORD_H

#include <QGraphicsTextItem>
#include <QString>
class Word: public QGraphicsTextItem
{
private:
    QString randomWord();
public:
    QString word;
    Word(QString word, QGraphicsItem *parent);
    void RemoveFirstCharacter();
    void VisualRemoveFirstCharacter();
    void UpdateWord();
};

#endif // WORD_H

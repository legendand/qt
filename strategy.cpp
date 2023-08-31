#include "strategy.h"

#include <QMap>

Strategy::Strategy(Player* player,Cards cards)
{
    m_player = player;
    m_cards  = cards;
}

Strategy::~Strategy()
{

}

QVector<Cards> Strategy::findHand(PlayHand hand,bool beat)
{
    PlayHand::HandType handType = hand.getType();
    Card::CardPoint basePoint = hand.getBasePoint();
    int extra = hand.getExtra();//多少连、多少连对

    if(handType == PlayHand::Hand_Pass)
    {

    }
    else if (handType == PlayHand::Hand_Single)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ?
                    Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);
        for (Card::CardPoint point = beginPoint; point < Card::Card_End; point=Card::CardPoint(point+1)) {
            Cards findCards = findSamePointCards(point,1);
            if(!findCards.isEmpty())
            {
                findCardsArray << findCards;
            }
        }
        return findCardsArray;
    }
    else if(handType == PlayHand::Hand_Pair)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ?
                    Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);

        for(Card::CardPoint point = beginPoint; point <Card::Card_End;point=Card::CardPoint(point+1))
        {
            Cards findCards = findSamePointCards(point,2);
            if(!findCards.isEmpty())
            {
                findCardsArray << findCards;
            }
        }
        return findCardsArray;
    }
    else if(handType == PlayHand::Hand_Triple)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ?
                    Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);

        for(Card::CardPoint point = beginPoint; point <Card::Card_End;point=Card::CardPoint(point+1))
        {
            Cards findCards = findSamePointCards(point,3);
            if(!findCards.isEmpty())
            {
                findCardsArray << findCards;
            }
        }
        return findCardsArray;

    }
    else if (handType == PlayHand::Hand_Triple_Single)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ?
                    Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);

        for(Card::CardPoint point = beginPoint; point <Card::Card_End;point=Card::CardPoint(point+1))
        {
            Cards findCards = findSamePointCards(point,3);
            if(!findCards.isEmpty())
            {
                findCardsArray << findCards;
            }
        }
        if(!findCardsArray.isEmpty())
        {
            Cards remainCards = m_cards;
            remainCards.remove(findCardsArray);

            Strategy st(m_player,remainCards);
            QVector<Cards> oneCardsArray = st.findHand(PlayHand(PlayHand::Hand_Single,Card::Card_Begin,0),false);
            if(!oneCardsArray.isEmpty())
            {
                for (int i = 0; i < findCardsArray.size(); ++i) {
                   findCardsArray[i].add(oneCardsArray[0]);//带最小的
                }
            }
            else{
                findCardsArray.clear();
            }
        }
        return findCardsArray;
    }
    else if(handType == PlayHand::Hand_Triple_Pair)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ?
                    Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);

        for(Card::CardPoint point = beginPoint; point <Card::Card_End;point=Card::CardPoint(point+1))
        {
            Cards findCards = findSamePointCards(point,3);
            if(!findCards.isEmpty())
            {
                findCardsArray << findCards;
            }
        }
        if(!findCardsArray.isEmpty())
        {
            Cards remainCards = m_cards;
            remainCards.remove(findCardsArray);

            Strategy st(m_player,remainCards);
            QVector<Cards> twoCardsArray = st.findHand(PlayHand(PlayHand::Hand_Pair,Card::Card_Begin,0),false);
            if(!twoCardsArray.isEmpty())
            {
                for (int i = 0; i < findCardsArray.size(); ++i) {
                   findCardsArray[i].add(twoCardsArray[0]);//带最小的对
                }
            }
            else{
                findCardsArray.clear();
            }
        }
        return findCardsArray;
    }
    else if (handType == PlayHand::Hand_Plane)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ? Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);
        for (Card::CardPoint point = beginPoint; point < Card::Card_K; point=Card::CardPoint(point+1)) {
            Cards prevCards = findSamePointCards(point,3);//找小的
            Cards nextCards = findSamePointCards(Card::CardPoint(point+1),3);//找大的
            if(!prevCards.isEmpty() && !nextCards.isEmpty())
            {
                findCardsArray << prevCards << nextCards;
            }
        }

        return findCardsArray;
    }
    else if(handType == PlayHand::Hand_Plane_Two_Single)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ? Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);
        for (Card::CardPoint point = beginPoint; point < Card::Card_K; point=Card::CardPoint(point+1)) {
            Cards prevCards = findSamePointCards(point,3);
            Cards nextCards = findSamePointCards(Card::CardPoint(point+1),3);
            if(!prevCards.isEmpty() && !nextCards.isEmpty())
            {
                Cards findCards;//存两张单牌
                findCardsArray << prevCards << nextCards;
                findCardsArray << findCards;//加到数组首，一会儿找到单牌直接加进去
            }
        }

        if(!findCardsArray.isEmpty())
        {
            Cards remainCards = m_cards;
            remainCards.remove(findCardsArray);

            Strategy st(m_player,remainCards);
            QVector<Cards> oneCardsArray = st.findHand(PlayHand(PlayHand::Hand_Single,Card::Card_Begin,0),false);
            if(oneCardsArray.size() >= 2)//有两张以上的单牌
            {
                for (int i = 0; i < findCardsArray.size(); ++i) {
                   Cards oneCards;
                   oneCards << oneCardsArray[0] << oneCardsArray[1];//最小的两张
                   findCardsArray[i] << oneCards;
                }
            }
            else{
                findCardsArray.clear();
            }
        }

        return findCardsArray;
    }

    else if(handType == PlayHand::Hand_Plane_Two_Pair)
    {
        QVector<Cards> findCardsArray;

        Card::CardPoint beginPoint = beat ? Card::CardPoint(basePoint+1) : Card::CardPoint(Card::Card_Begin+1);
        for (Card::CardPoint point = beginPoint; point < Card::Card_K; point=Card::CardPoint(point+1)) {
            Cards prevCards = findSamePointCards(point,3);
            Cards nextCards = findSamePointCards(Card::CardPoint(point+1),3);
            if(!prevCards.isEmpty() && !nextCards.isEmpty())
            {
                Cards findCards;
                findCardsArray << prevCards << nextCards;
                findCardsArray << findCards;
            }
        }

        if(!findCardsArray.isEmpty())
        {
            Cards remainCards = m_cards;
            remainCards.remove(findCardsArray);

            Strategy st(m_player,remainCards);
            QVector<Cards> pairCardsArray = st.findHand(PlayHand(PlayHand::Hand_Pair,Card::Card_Begin,0),false);
            if(pairCardsArray.size() >= 2)
            {
                for (int i = 0; i < findCardsArray.size(); ++i) {
                   Cards pairCards;
                   pairCards << pairCardsArray[0] << pairCardsArray[1];
                   findCardsArray[i] << pairCards;
                }
            }
            else{
                findCardsArray.clear();
            }
        }

        return findCardsArray;
    }
    else if(handType == PlayHand::Hand_Seq_Pair)
    {
        if(beat)
        {
            QVector<Cards> findCardsArray;
            //最大连对，从Q开始
            for (Card::CardPoint point = Card::CardPoint(basePoint+1); point < Card::Card_Q; point = Card::CardPoint(point+1)) {
                bool seqPairFound =true;
                Cards seqPair;

                for (int i = 0; i < extra; ++i) {
                   Cards cards = findSamePointCards(Card::CardPoint(point+i),2);
                   if(cards.isEmpty() || (point + i >= Card::Card_2))//连对中断，或者到2了
                   {
                       seqPairFound = false;
                       seqPair.clear();
                       break;
                   }
                   else{
                       seqPair << cards;
                   }
                }

                if(seqPairFound)
                {
                    findCardsArray << seqPair;
                    return findCardsArray;
                }
            }
            return findCardsArray;
        }
        else
        {
            QVector<Cards> findCardsArray;

            for(Card::CardPoint point = Card::Card_3;point <= Card::Card_Q;point=Card::CardPoint(point+1))
            {
                Cards cards0 = findSamePointCards(point,2);
                Cards cards1 = findSamePointCards(Card::CardPoint(point+1),2);
                Cards cards2 = findSamePointCards(Card::CardPoint(point+2),2);

                if(cards0.isEmpty() || cards1.isEmpty() || cards2.isEmpty()) continue;

                Cards baseSeq;
                baseSeq << cards0 << cards1 << cards2;
                findCardsArray << baseSeq;

                int followed = 3;
                Cards alreadyFollowedCards;

                while(true)
                {
                    Card::CardPoint followedPoint = Card::CardPoint(point + followed);
                    if(followedPoint >= Card::Card::Card_2)
                    {
                        break;
                    }

                    Cards followedCards = findSamePointCards(followedPoint,2);
                    if(followedCards.isEmpty())
                    {
                        break;
                    }
                    else
                    {
                        alreadyFollowedCards << followedCards;
                        Cards newSeq = baseSeq;
                        newSeq << alreadyFollowedCards;

                        findCardsArray << newSeq;
                        followed++;
                    }
                }
            }
            return findCardsArray;
        }
    }
    else if(handType == PlayHand::Hand_Seq_Single)//顺子
    {
        if(beat)
        {
            QVector<Cards> findCardsArray;
            for(Card::CardPoint point = Card::CardPoint(basePoint+1);point <= Card::Card_10; point=Card::CardPoint(point+1))
            {
                bool seqSingleFound = true;
                Cards seqSingle;

                for (int i = 0; i < extra; ++i) {
                   Cards cards =findSamePointCards(Card::CardPoint(point+i),1);
                   if(cards.isEmpty() || (point+ extra) >=Card::Card_2)
                   {
                       seqSingleFound = false;
                       seqSingle.clear();
                       break;
                   }
                   else
                   {
                       seqSingle << cards;
                   }
                }

                if(seqSingleFound)
                {
                    findCardsArray << seqSingle;
                    return findCardsArray;
                }
            }
        }
        else{
            QVector<Cards> findCardsArray;

            for(Card::CardPoint point = Card::Card_3; point <= Card::Card_10; point= Card::CardPoint(point+1))
            {
                Cards cards0 = findSamePointCards(point,1);
                Cards cards1 = findSamePointCards(Card::CardPoint(point+1),1);
                Cards cards2 = findSamePointCards(Card::CardPoint(point+2),1);
                Cards cards3 = findSamePointCards(Card::CardPoint(point+3),1);
                Cards cards4 = findSamePointCards(Card::CardPoint(point+4),1);

                if(cards0.isEmpty() || cards1.isEmpty() || cards2.isEmpty() || cards3.isEmpty()
                        || cards4.isEmpty())
                {
                    continue;
                }

                Cards baseSeq;
                baseSeq << cards0 <<cards1 <<cards2 << cards3 << cards4;
                findCardsArray << baseSeq;

                int followed = 5;
                Cards alreadyFollowedCards;

                while(true)
                {
                    Card::CardPoint followedPoint = Card::CardPoint(point + followed);
                    if(followedPoint >= Card::Card_2)
                    {
                        break;
                    }

                    Cards followedCards = findSamePointCards(followedPoint,1);
                    if(followedCards.isEmpty())
                    {
                        break;
                    }
                    else
                    {
                        alreadyFollowedCards <<followedCards;
                        Cards newSeq = baseSeq;
                        newSeq << alreadyFollowedCards;

                        findCardsArray << newSeq;
                        followed++;
                    }
                }
            }
            return findCardsArray;
        }
    }
    /*else if (handType == PlayHand::PlayHand::Hand_Bomb_Single)
    {

    }*/
//    else if (handType == PlayHand::PlayHand::Hand_Bomb_Pair)
//    {

//    }
//    else if (handType == PlayHand::PlayHand::Hand_Bomb_Two_Single)
//    {

//    }

    return QVector<Cards>();
}


Cards Strategy::findSamePointCards(Card::CardPoint point,int count)
{
    if(point == Card::Card_SJ || point == Card::Card_BJ)
    {
        if(count>1) return Cards();//找两张以及以上的，不可能，返回空

        Card oneCard;
        oneCard.point = point;
        oneCard.suit = Card::Suit_Begin;//大小王花色都是begin

        if(m_cards.contains(oneCard))
        {
            Cards cards;
            cards.add(oneCard);
            return cards;
        }

        return Cards();
    }

    Cards findCards;
    int findCount = 0;
    for (int suit = Card::Suit_Begin+1; suit < Card::Suit_End; ++suit) {
        Card oneCard;
        oneCard.point = point;
        oneCard.suit = (Card::CardSuit)suit;

        if(m_cards.contains(oneCard))
        {
            findCount++;
            findCards << oneCard;

            if(findCount==count)
            {
                return findCards;
            }
        }
    }

    return Cards();
}

//找出所有count张牌，比如所有对
QVector<Cards> Strategy::findCardsByCount(int count)
{
    QVector<Cards> cardsArray;
    if(count <1 || count>4) return cardsArray;//所有单/双/3/4的牌，否则返回空

    for (Card::CardPoint point = Card::Card_3; point < Card::Card_End; point=Card::CardPoint(point+1))
    {
        if(m_cards.pointCount(point)==count)
        {
            Cards cards;
            cards << findSamePointCards(point,count);//找到那些牌，加入数组
            cardsArray << cards;
        }
    }
    return cardsArray;
}

Cards Strategy::getRangeCards(Card::CardPoint beginPoint,Card::CardPoint endPoint)
{
    Cards rangeCards;

    for (Card::CardPoint point = beginPoint; point <= endPoint; point=Card::CardPoint(point+1)) {
       int count=m_cards.pointCount(point);
       Cards cards=findSamePointCards(point,count);
       rangeCards << cards;
    }
    return rangeCards;
}

Cards Strategy::getFirstSeqSingleRange()
{
    int seqCount = 0;
    Card::CardPoint beginPoint,endPoint;
    beginPoint = endPoint = Card::Card_Begin;

    for (Card::CardPoint point = Card::Card_3; point <= Card::Card_10; point=Card::CardPoint(point+1)) {
        while(true)
        {
            Card::CardPoint findPoint = Card::CardPoint(point + seqCount);//要找的那张牌
            Cards oneCard = findSamePointCards(findPoint,1);
            if(oneCard.isEmpty() || findPoint > Card::Card_A)//这次while循环没找到该牌，或者找到了2、sj、bj
            {
                if(seqCount >= 5)//这次的找失效，但之前找的已经可以连
                {
                    endPoint = Card::CardPoint(point + seqCount-1);
                    return getRangeCards(beginPoint,endPoint);//顺子范围里的所有牌
                }

                point = findPoint;
                beginPoint = endPoint = Card::Card_Begin;
                seqCount=0;

                break;
            }
            else//这次while循环找到那张牌
            {
                if(seqCount==0)
                {
                    beginPoint = point;
                }

                seqCount++;
            }
        }
    }
    return Cards();
}

void Strategy::pickSeqSingles(QVector<QVector<Cards>>& allSeqRecord,const QVector<Cards>& seqInherited,Cards cards)
{
    // 在cards中挑出一个顺子，seqInherited记录逐步拨除顺子，allSeqRecord记录所能分离出的顺子
    QVector<Cards> allSeqScheme = Strategy(m_player,cards).findHand(PlayHand(PlayHand::Hand_Seq_Single,Card::Card_Begin,0),false);
    if(allSeqScheme.isEmpty())
    {
        allSeqRecord << seqInherited;
    }
    else
    {
        Cards savedCards =cards;
        for (int i = 0; i < allSeqScheme.size(); i++) {
            Cards aScheme = allSeqScheme[i];
            Cards LeftCards = savedCards;
            LeftCards.remove(aScheme);//挑出来一个方案，剩下的牌

            QVector<Cards> seqArray = seqInherited;
            seqArray << aScheme;

            pickSeqSingles(allSeqRecord,seqArray,LeftCards);//递归
        }
    }
}

QVector<Cards> Strategy::pickOptimalSeqSingles()
{
    QVector<QVector<Cards> > seqRecord;
    QVector<Cards> seqInherited;
    Strategy(m_player,m_cards).pickSeqSingles(seqRecord,seqInherited,m_cards);
    if(seqRecord.isEmpty()) return QVector<Cards>();//没有顺子

    QMap<int,int> seqMarks;

    for(int i=0; i< seqRecord.size();i++)
    {
        Cards backupCards = m_cards;
        QVector<Cards> seqArray = seqRecord[i];
        backupCards.remove(seqArray);//出完顺子剩下的牌

        QVector<Cards> singleArray = Strategy(m_player,backupCards).findCardsByCount(1);//找出(若出此顺子)剩的所有的单牌

        CardList cardList;
        for (int j = 0; j < singleArray.size(); ++j) {
           cardList << singleArray[j].toCardList();
        }

        int mark = 0;
        for (int j = 0; j < cardList.size(); ++j) {
           mark += cardList[j].point + 15;//剩的单牌越多，分数越高
        }//计算出剩余单牌的总分
        seqMarks.insert(i,mark);
    }

    int index=0;
    int compMark = 1000000;
    QMap<int,int>::ConstIterator it = seqMarks.constBegin();
    //依次比较所有可能情况下的评分，选出剩余牌评分最低的顺子出牌
    for(;it != seqMarks.constEnd(); it++)
    {
        if(it.value() < compMark)
        {
            compMark = it.value();
            index = it.key();
        }
    }
    return seqRecord[index];
}

Cards Strategy::playFirst()
{
    PlayHand hand(m_cards);
    if(hand.getType() != PlayHand::Hand_Unknown)
    {
        return m_cards;
    }

    Cards seqSingleRange = getFirstSeqSingleRange();
    if(!seqSingleRange.isEmpty())
    {
        Cards left = seqSingleRange;
        left.remove(Strategy(m_player,left).findCardsByCount(4));
        left.remove(Strategy(m_player,left).findCardsByCount(3));
        QVector<Cards> optimalSeq = Strategy(m_player,left).pickOptimalSeqSingles();

        if(!optimalSeq.isEmpty())
        {
            int oriSingleCount = Strategy(m_player,left).findCardsByCount(1).size();
            left.remove(optimalSeq);
            int leftSingleCount = Strategy(m_player,left).findCardsByCount(1).size();

            if(leftSingleCount < oriSingleCount)
            {
                return optimalSeq[0];
            }
        }
    }

    bool hasPlane,hasTriple,hasSeqPair;
    hasPlane = hasTriple = hasSeqPair =false;
    Cards leftCards = m_cards;

    QVector<Cards> bomArray =Strategy(m_player,leftCards).findHand(PlayHand(PlayHand::Hand_Bomb,Card::Card_Begin,0),false);
    leftCards.remove(bomArray);

    QVector<Cards> planeArray = Strategy(m_player,leftCards).findHand(PlayHand(PlayHand::Hand_Plane,Card::Card_Begin,0),false);
    if(!planeArray.isEmpty())
    {
        hasPlane = true;
        leftCards.remove(planeArray);
    }

    QVector<Cards> tripleArray = Strategy(m_player,leftCards).findHand(PlayHand(PlayHand::Hand_Triple,Card::Card_Begin,0),false);
    if(!tripleArray.isEmpty())
    {
        hasTriple = true;
        leftCards.remove(tripleArray);
    }

    QVector<Cards> seqPairArray = Strategy(m_player,leftCards).findHand(PlayHand(PlayHand::Hand_Seq_Pair,Card::Card_Begin,0),false);
    if(!seqPairArray.isEmpty())
    {
        hasSeqPair = true;
        leftCards.remove(seqPairArray);
    }

    if(hasPlane)
    {
        bool twoPairFound = false;
        QVector<Cards> pairArray;
        for (Card::CardPoint point = Card::Card_3; point <= Card::Card_A; point=Card::CardPoint(point+1)) {
            Cards pair = Strategy(m_player,leftCards).findSamePointCards(point,2);
            if(!pair.isEmpty())
            {
                pairArray << pair;
                if(pairArray.size() == 2)
                {
                    twoPairFound = true;
                    break;
                }
            }
        }

        if(twoPairFound)
        {
            Cards playCards = planeArray[0];
            playCards.add(pairArray);

            return playCards;
        }
        else
        {
            bool twoSingleFound = false;
            QVector<Cards> singleArray;
            for (Card::CardPoint point = Card::Card_3; point <= Card::Card_A; point = Card::CardPoint(point+1)) {
                if(leftCards.pointCount(point)==1)
                {
                    Cards single = Strategy(m_player,leftCards).findSamePointCards(point,1);
                    if(!single.isEmpty())
                    {
                        singleArray << single;
                        if(singleArray.size() == 2)
                        {
                            twoSingleFound =true;
                            break;
                        }
                    }
                }
            }

            if(twoSingleFound)
            {
                Cards playCards = planeArray[0];
                playCards.add(singleArray);

                return playCards;
            }
            else
            {
                return planeArray[0];
            }
        }
    }

    if(hasTriple)
    {
        if(PlayHand(tripleArray[0]).getBasePoint() < Card::Card_A)
        {
            for (Card::CardPoint point = Card::Card_3; point <= Card::Card_A; point=Card::CardPoint(point+1)) {
                int pointCount = leftCards.pointCount(point);
                if(pointCount==1)
                {
                    Cards single = Strategy(m_player,leftCards).findSamePointCards(point,1);
                    if(!single.isEmpty())
                    {
                        Cards playCards = tripleArray[0];
                        playCards.add(single);

                        return playCards;
                    }
                }
                else if(pointCount==2)
                {
                    Cards pair = Strategy(m_player,leftCards).findSamePointCards(point,2);
                    if(!pair.isEmpty())
                    {
                        Cards playCards = tripleArray[0];
                        playCards.add(pair);

                        return playCards;
                    }
                }
            }
            return tripleArray[0];//找不到合适的带的牌，直接出，不带
        }
    }

    if(hasSeqPair)  //打出最长的连对
    {
        Cards maxSeqpair;
        for (int i = 0; i < seqPairArray.size(); ++i) {
           if(seqPairArray[i].cardCount() > maxSeqpair.cardCount())
           {
               maxSeqpair = seqPairArray[i];
           }
        }

        return maxSeqpair;
    }

    Player* nextPlayer = m_player->getNextPlayer();

    if(m_player->getRole() != nextPlayer ->getRole() && nextPlayer->getCards().cardCount() == 1)
    {
        for (Card::CardPoint point = Card::CardPoint(Card::Card_End-1); point >= Card::Card_3; point=Card::CardPoint(point-1))
        {
            int pointCount = leftCards.pointCount(point);
            if(pointCount==1)
            {
                Cards single = Strategy(m_player,leftCards).findSamePointCards(point,1);
                return single;
            }
            else if(pointCount == 2)
            {
                Cards pair = Strategy(m_player,leftCards).findSamePointCards(point,2);
                return pair;
            }
        }
    }
    else
    {
        for (Card::CardPoint point = Card::Card_3; point < Card::Card_End; point=Card::CardPoint(point+1)) {
            int pointCount = leftCards.pointCount(point);
            if(pointCount == 1)
            {
                Cards single = Strategy(m_player,leftCards).findSamePointCards(point,1);
                return single;
            }
            else if(pointCount == 2)
            {
                Cards pair = Strategy(m_player,leftCards).findSamePointCards(point,2);
                return pair;
            }
        }
    }
    return Cards();

}

Cards Strategy::playBeatHand(PlayHand hand)
{
    //先固定住最优顺子，从余下牌中打出
    Cards left = m_cards;
    left.remove(Strategy(m_player,left).pickOptimalSeqSingles());

    if(hand.getType() == PlayHand::Hand_Single)//如果压单牌，尽量从单张牌中挑
    {
        QVector<Cards> singleArray = Strategy(m_player,left).findCardsByCount(1);
        for (int i = 0; i < singleArray.size(); ++i) {
           if(PlayHand(singleArray[i]).canBeat(hand))
           {
               return singleArray[i];
           }
        }
    }
    else if(hand.getType() == PlayHand::Hand_Pair)//若压对，尽量从双牌里挑
    {
        QVector<Cards> pairArray = Strategy(m_player,left).findCardsByCount(2);
        for (int i = 0; i < pairArray.size(); ++i) {
           if(PlayHand(pairArray[i]).canBeat(hand))
           {
               return pairArray[i];
           }
        }
    }

    Player* nextPlayer = m_player->getNextPlayer();
    QVector<Cards> beatCardsArray = Strategy(m_player,left).findHand(hand,true);
    if(!beatCardsArray.isEmpty())
    {
        if(m_player->getRole() != nextPlayer->getRole() && nextPlayer->getCards().cardCount() <= 2)
        {
            return beatCardsArray.back();//返回最后一个元素的引用
        }
        else
        {
            return beatCardsArray.front();//返回第一个元素的引用
        }
    }
    else //余下牌没法打时，只好从顺子里挑牌
    {
        beatCardsArray = Strategy(m_player,m_cards).findHand(hand,true);
        if(!beatCardsArray.isEmpty())
        {
            if(m_player->getRole() != nextPlayer->getRole() && nextPlayer->getCards().cardCount() <=2)
            {
                return beatCardsArray.back();
            }
            else
            {
                return beatCardsArray.front();
            }
        }
    }
    //对家剩牌小于三张，有炸就炸
    Player* punchPlayer = m_player->getPendPlayer();//上家，刚出完牌，轮到自己
    if(m_player->getRole() != punchPlayer->getRole())
    {
        if(punchPlayer->getCards().cardCount() <= 3)
        {
            QVector<Cards> bombs =findCardsByCount(4);
            if(!bombs.isEmpty())
            {
                return bombs[0];
            }
        }
    }
    return Cards();
}

bool Strategy::whetherToBeat(Cards& myCards)
{
    if(myCards.isEmpty()) return true;

    Player* punchPlayer = m_player->getPendPlayer();
    Cards punchCards =m_player->getPendCards();

    if(m_player->getRole() == punchPlayer->getRole())
    {
        Cards left = m_cards;
        left.remove(myCards);
        if(PlayHand(left).getType() != PlayHand::Hand_Unknown) return true;

        Card::CardPoint basePoint = PlayHand(myCards).getBasePoint();
        if(basePoint == Card::Card_2 || basePoint == Card::Card_SJ || basePoint == Card::Card_BJ)
        {
            return false;
        }
    }
    else //punch是对家，非本方
    {
        PlayHand myHand(myCards);

        if((myHand.getType() == PlayHand::Hand_Triple_Single || myHand.getType() == PlayHand::Hand_Triple_Pair)
                && (myHand.getBasePoint() == Card::Card_2) )//三个2就不打出去了
        {
            return false;
        }

        if(myHand.getType() == PlayHand::Hand_Pair && myHand.getBasePoint() == Card::Card_2 &&
                punchPlayer->getCards().cardCount() >= 10 && m_player->getCards().cardCount() >=5)

        {
            return false;
        }
    }
    return true;
}

Cards Strategy::makeStrategy()
{
    Player* punchPlayer = m_player->getPendPlayer();
    Cards punchCards = m_player->getPendCards();

    if(punchPlayer == m_player || punchPlayer == NULL)
    {
        return playFirst();
    }
    else
    {
        PlayHand punchHand(punchCards);
        Cards beatCards = playBeatHand(punchHand);
        bool shouldBeat = whetherToBeat(beatCards);
        if(shouldBeat)
        {
            return beatCards;
        }
        else{
            return Cards();
        }
    }

    return Cards();
}


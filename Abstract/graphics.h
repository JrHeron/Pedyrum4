#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class Graphics : public QWidget
{
    Q_OBJECT
public:
    explicit Graphics(QWidget *parent = 0);

private:
    enum types{
        Sectors,
        Bars,
        Lines
    };

public: // fun��es
    void setData(QList<float> data);
    void setData(QList < QList< float > > data);
    void setColors(QList < QColor > colors);
    void setBackgroundColor(int r, int g, int b);
    void setBackgroundColor(QColor color);
    void setMargins(int left, int right, int top, int button);
    void setLegend(QList<QString> legend);
    void setType(Graphics::types type); // pode ser "lines" ou "sectors" ou, futuramente, "bars"

    QList<QList<float > > getData();


protected: // fun��es
    void paintEvent(QPaintEvent *); // fun��o padr�o sempre chamada
    void drawSectors(); // desenha o grafico de setores
    void drawLegend(); // pinta a legenda no gr�fico
    void drawMask(); // desenha as mascaras do grafico
    void drawBackground(); // pinta o fundo do widget


    bool drawLines(); // o de linhas

    int py(int pY); // fun��o para inverter os valores

    float getPercentage();
    float getMax(QList<QList<float> > data);

    QList <QList <float> > adjustValues(); // ajusta os valores para desenhar o grafico
    QList <QList <float> > adjustValues(float porcentagem);

protected: // variaveis
    QList < QList< float > > data;
    QList < QColor > colors;

    //variaveis de margem
    int left;
    int right;
    int top;
    int button;

    // variaveis de desenho do fundo do gr�fico
    bool verticalLines;
    bool horizontalLines;

    // tipo do gr�fico a ser exibido
    Graphics::types type;

    // variavel que ter� o valor da linha mais alta
    int maxLine;

    // variaveis da cor do fundo do widget
    struct{
        int r,g,b;
    }backgroundColor;

    // variavel de legenda do gr�fico
    QList<QString> legend;


signals:

public slots:

};

#endif // GRAPHICS_H

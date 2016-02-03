#include "bossindex.h"
#include <iostream>

const BossIndex bossIndex;

int BossIndex::index = 0;

BossIndex::BossIndex()
{
    (*this)["Abrichter Darmac"] = 153;
    (*this)["Al'Akir"] = 82;
    (*this)["Algalon der Beobachter"] = 47;
    (*this)["Alizabal, Herrin des Hasses"] = 69;
    (*this)["Alysrazar"] = 86;
    (*this)["Anub'Rekhan"] = 17;
    (*this)["Anub'arak"] = 53;
    (*this)["Archavon der Steinwächter"] = 13;
    (*this)["Archimonde"] = 10;
    (*this)["Argaloth"] = 67;
    (*this)["Atramedes"] = 72;
    (*this)["Auriaya"] = 40;
    (*this)["Baloroc, der Torwächter"] = 87;
    (*this)["Belagerungsingenieur Rußschmied"] = 137;
    (*this)["Bernformer Un'sok"] = 107;
    (*this)["Beschützer des Endlosen"] = 109;
    (*this)["Bestien von Nordend"] = 49;
    (*this)["Beth'tilac"] = 83;
    (*this)["Blutkönigin Lana'thel"] = 62;
    (*this)["Blutschatten"] = 162;
    (*this)["C'Thun"] = 4;
    (*this)["Cho'gall"] = 79;
    (*this)["Das Konklave des Windes"] = 81;
    (*this)["Der Lichkönig"] = 65;
    (*this)["Der Schlächter"] = 141;
    (*this)["Der Schmelzofen"] = 149;
    (*this)["Der Wille des Kaisers"] = 102;
    (*this)["Der eiserne Qon"] = 122;
    (*this)["Die Eisernen Jungfern"] = 155;
    (*this)["Die Geisterkönige"] = 100;
    (*this)["Die Getreuen der Klaxxi"] = 138;
    (*this)["Die Schätze Pandarias"] = 135;
    (*this)["Die Steinwache"] = 97;
    (*this)["Die Versammlung des Eisens"] = 38;
    (*this)["Die gefallenen Beschützer"] = 127;
    (*this)["Die vier Reiter"] = 25;
    (*this)["Dunkelschamanen der Kor'kron"] = 132;
    (*this)["Dunkler Animus"] = 121;
    (*this)["Durumu der Vergessene"] = 119;
    (*this)["Eiserner Häscher"] = 158;
    (*this)["Eiserner Koloss"] = 131;
    (*this)["Elegon"] = 101;
    (*this)["Emalon der Sturmwächter"] = 14;
    (*this)["Erzfresser"] = 147;
    (*this)["Farnspore"] = 142;
    (*this)["Fauldarm"] = 59;
    (*this)["Feng der Verfluchte"] = 98;
    (*this)["Flammenbändigerin Ka'graz"] = 151;
    (*this)["Flammenleviathan"] = 34;
    (*this)["Flickwerk"] = 26;
    (*this)["Fraktionschampions"] = 51;
    (*this)["Freya"] = 43;
    (*this)["Galakras"] = 130;
    (*this)["Gara'jal der Geisterbinder"] = 99;
    (*this)["Garalon"] = 105;
    (*this)["Garrosh Höllschrei"] = 139;
    (*this)["General Nazgrim"] = 133;
    (*this)["General Vezax"] = 45;
    (*this)["Gluth"] = 28;
    (*this)["Gothik der Ernter"] = 24;
    (*this)["Grobbulus"] = 27;
    (*this)["Großkaiserin Shek'zeer"] = 108;
    (*this)["Großwitwe Faerlina"] = 18;
    (*this)["Gruul"] = 148;
    (*this)["Gruul der Drachenschlächter"] = 7;
    (*this)["Hagara die Sturmbinderin"] = 92;
    (*this)["Halfus Wyrmbrecher"] = 76;
    (*this)["Halion"] = 66;
    (*this)["Hans'gar und Franzok"] = 150;
    (*this)["Heigan der Unreine"] = 21;
    (*this)["Hodir"] = 41;
    (*this)["Hoher Rat des Höllenfeuers"] = 160;
    (*this)["Horridon"] = 114;
    (*this)["Höllenfeuerangriff"] = 157;
    (*this)["Ignis, Meister des Eisenwerks"] = 35;
    (*this)["Illidan Sturmgrimm"] = 11;
    (*this)["Immerseus"] = 126;
    (*this)["Instrukteur Razuvious"] = 23;
    (*this)["Ji-Kun"] = 118;
    (*this)["Jin'rokh der Zerstörer"] = 113;
    (*this)["Kael'thas Sonnenwanderer"] = 9;
    (*this)["Kaiser Mar'gok"] = 146;
    (*this)["Kaiserlicher Wesir Zor'lok"] = 103;
    (*this)["Kanonenschiffsschlacht von Eiskrone"] = 56;
    (*this)["Kargath Messerfaust"] = 140;
    (*this)["Kel'Thuzad"] = 31;
    (*this)["Kil'jaeden"] = 12;
    (*this)["Kilrogg Totauge"] = 161;
    (*this)["Klingenfürst Ta'yak"] = 104;
    (*this)["Klingenschuppe"] = 36;
    (*this)["Ko'ragh"] = 145;
    (*this)["Kologarn"] = 39;
    (*this)["Koralon der Flammenwächter"] = 15;
    (*this)["Kormrok"] = 159;
    (*this)["Kriegsherr Zon'ozz"] = 90;
    (*this)["Kriegsmeister Schwarzhorn"] = 94;
    (*this)["Kromog"] = 152;
    (*this)["Lady Todeswisper"] = 55;
    (*this)["Lady Vashj"] = 8;
    (*this)["Lei Shen"] = 124;
    (*this)["Lei Shi"] = 111;
    (*this)["Loatheb"] = 22;
    (*this)["Lord Jaraxxus"] = 50;
    (*this)["Lord Mark'gar"] = 54;
    (*this)["Lord Rhyolith"] = 84;
    (*this)["Maexxna"] = 19;
    (*this)["Magmaul"] = 71;
    (*this)["Magtheridon"] = 6;
    (*this)["Majordomus Hirschhaupt"] = 88;
    (*this)["Malkorok"] = 134;
    (*this)["Maloriak"] = 74;
    (*this)["Malygos"] = 33;
    (*this)["Mannoroth"] = 168;
    (*this)["Megaera"] = 117;
    (*this)["Mimiron"] = 44;
    (*this)["Modermiene"] = 58;
    (*this)["Morchok"] = 89;
    (*this)["Nefarian"] = 2;
    (*this)["Nefarians Ende"] = 75;
    (*this)["Norushen"] = 128;
    (*this)["Noth der Seuchenfürst"] = 20;
    (*this)["Occu'thar"] = 68;
    (*this)["Ogronzwillinge"] = 144;
    (*this)["Omnotron-Verteidigungssystem"] = 70;
    (*this)["Onyxia"] = 48;
    (*this)["Ossirian der Narbenlose"] = 3;
    (*this)["Primordius"] = 120;
    (*this)["Prinz Malchezaar"] = 5;
    (*this)["Professor Seuchenmord"] = 60;
    (*this)["Ra-den"] = 125;
    (*this)["Ragnaros"] = 1;
    (*this)["Rat der Aszendenten"] = 78;
    (*this)["Rat der Ältesten"] = 115;
    (*this)["Rat des Blutes"] = 61;
    (*this)["Saphiron"] = 30;
    (*this)["Sartharion"] = 32;
    (*this)["Schattenfürst Iskar"] = 163;
    (*this)["Schimaeron"] = 73;
    (*this)["Schwarzfaust"] = 156;
    (*this)["Sha der Angst"] = 112;
    (*this)["Sha des Stolzes"] = 129;
    (*this)["Shannox"] = 85;
    (*this)["Sindragosa"] = 64;
    (*this)["Sinestra"] = 80;
    (*this)["Socrethar der Ewige"] = 164;
    (*this)["Tectus"] = 143;
    (*this)["Teufelslord Zakuun"] = 166;
    (*this)["Thaddius"] = 29;
    (*this)["Theralion und Valiona"] = 77;
    (*this)["Thok der Blutrünstige"] = 136;
    (*this)["Thorim"] = 42;
    (*this)["Todesbringer Saurfang"] = 57;
    (*this)["Todesschwinges Rückgrat"] = 95;
    (*this)["Todesschwinges Wahnsinn"] = 96;
    (*this)["Toravon der Eiswächter"] = 16;
    (*this)["Tortos"] = 116;
    (*this)["Tsulong"] = 110;
    (*this)["Tyrannin Velhari"] = 165;
    (*this)["Ultraxion"] = 93;
    (*this)["Valithria Traumwandler"] = 63;
    (*this)["Windfürst Mel'jarak"] = 106;
    (*this)["XT-002 Dekonstruktor"] = 37;
    (*this)["Xhul'horac"] = 167;
    (*this)["Yogg-Saron"] = 46;
    (*this)["Yor'sahj der Unermüdliche"] = 91;
    (*this)["Zugführer Thogar"] = 154;
    (*this)["Zwillingskonkubinen"] = 123;
    (*this)["Zwillingsval'kyr"] = 52;
}
/*
int &BossIndex::operator[](const QString &key) {
    if (!QMap::contains(key)) {
        index++;
        QMap::operator [](key) = index;
    }
    return QMap::operator [](key);
}
*/
void BossIndex::save() {
    for(const QString key: (*this).keys()) {
        std::cout << "bossIndex[\"" << key.toUtf8().constData() << "\"] = " << (*this)[key] << ";" << std::endl;
    }
    std::cout << "constexpr int nBoss = " << index << ";" << std::endl;
}

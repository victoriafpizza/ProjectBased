// ============================================================
//  BRAÇO ROBÓTICO — Garra (Gripper) para Coleta de Amostras
//  Docking & Retrieval System — Microgravidade
//  Software: OpenSCAD
// ============================================================
//  Descrição:
//    Modelo 3D da garra do braço robótico espacial.
//    Composta por: base central, dois dedos articuláveis
//    e encaixe para servo motor 9g (ex: SG90).
//
//    Todas as dimensões são parametrizadas via variáveis
//    para facilitar ajustes de escala e adaptação.
// ============================================================

// ── PARÂMETROS GLOBAIS ──────────────────────────────────────
$fn = 64;  // Qualidade de curvas (aumentar = mais suave)

// ── Parâmetros da Base Central ──────────────────────────────
base_largura   = 40;   // mm — largura da base
base_altura    = 12;   // mm — altura/espessura da base
base_comp      = 38;   // mm — comprimento da base
raio_canto     = 3;    // mm — arredondamento dos cantos

// ── Parâmetros do Dedo / Elo ────────────────────────────────
dedo_comp      = 45;   // mm — comprimento de cada dedo
dedo_larg      = 10;   // mm — largura do dedo
dedo_esp       = 7;    // mm — espessura do dedo
dedo_raio_tip  = 4;    // mm — raio da ponta do dedo (tip)
afastamento    = 6;    // mm — distância entre dedos (abertura mín.)

// ── Parâmetros do Encaixe do Servo 9g ───────────────────────
servo_comp     = 23;   // mm — comprimento do servo SG90
servo_larg     = 12.5; // mm — largura do servo SG90
servo_prof     = 10;   // mm — profundidade do encaixe
servo_offset_x = 0;    // mm — offset lateral do encaixe
servo_offset_z = 2;    // mm — elevação do encaixe na base

// ── Parâmetros do Eixo de Pivô ──────────────────────────────
pivo_raio      = 2.5;  // mm — raio do furo de pivô nos dedos
pivo_offset_y  = 6;    // mm — posição do pivô a partir da base do dedo

// ── Parâmetros de Nervuras (reforço estrutural) ─────────────
nervura_esp    = 1.5;  // mm — espessura das nervuras
nervura_altura = 8;    // mm — altura das nervuras

// ── Cor para visualização ────────────────────────────────────
cor_base   = [0.15, 0.15, 0.20];  // cinza escuro espacial
cor_dedo   = [0.20, 0.55, 0.80];  // azul-aço
cor_detalhe= [0.85, 0.85, 0.90];  // prata


// ============================================================
//  MONTAGEM COMPLETA
// ============================================================
module montagem_completa() {
    // Base central
    color(cor_base) base_central();

    // Dedo esquerdo
    color(cor_dedo)
        translate([-base_largura/2 + dedo_larg/2, base_comp/2 - pivo_offset_y, base_altura])
            dedo();

    // Dedo direito (espelhado)
    color(cor_dedo)
        translate([base_largura/2 - dedo_larg/2, base_comp/2 - pivo_offset_y, base_altura])
            mirror([1,0,0]) dedo();

    // Tampa superior com logo gravado
    color(cor_detalhe)
        translate([0, 0, base_altura])
            tampa_logo();
}

// ============================================================
//  BASE CENTRAL
//  Corpo principal com encaixe para servo 9g e nervuras
// ============================================================
module base_central() {
    difference() {
        // Corpo principal — cuboide com cantos arredondados
        minkowski() {
            cube([base_largura - 2*raio_canto,
                  base_comp    - 2*raio_canto,
                  base_altura - 1], center=true);
            cylinder(r=raio_canto, h=1, center=true);
        }

        // Cavidade do servo 9g
        translate([servo_offset_x, 0, -base_altura/2 + servo_offset_z])
            cube([servo_larg, servo_comp, servo_prof + 1], center=true);

        // Furo de passagem do cabo
        translate([servo_offset_x, -base_comp/2 + 3, -base_altura/2 + servo_offset_z + 2])
            rotate([90,0,0])
                cylinder(r=2, h=6, center=true);

        // Furos de montagem nos cantos (M3)
        for (sx=[-1,1]) for (sy=[-1,1])
            translate([sx*(base_largura/2 - 5), sy*(base_comp/2 - 5), 0])
                cylinder(r=1.6, h=base_altura + 2, center=true);
    }

    // Nervuras laterais de reforço
    for (sx=[-1,1])
        translate([sx*(base_largura/2 - nervura_esp/2 - 1), 0, 0])
            cube([nervura_esp, base_comp - 4, nervura_altura], center=true);
}

// ============================================================
//  DEDO (elo articulável)
//  Forma aerodinâmica com ponta curva para captura
// ============================================================
module dedo() {
    difference() {
        union() {
            // Corpo principal do dedo
            hull() {
                // Base do dedo (larga)
                cube([dedo_larg, dedo_esp, 2], center=true);

                // Meio do dedo
                translate([0, dedo_comp * 0.5, dedo_comp * 0.15])
                    cube([dedo_larg * 0.75, dedo_esp * 0.8, 2], center=true);

                // Ponta curvada (tip) — voltada para dentro
                translate([dedo_larg * 0.05, dedo_comp, dedo_comp * 0.35])
                    sphere(r=dedo_raio_tip);
            }

            // Reforço na base (flange de montagem)
            translate([0, -dedo_esp/2, dedo_esp/2])
                cube([dedo_larg + 4, dedo_esp, dedo_esp], center=true);
        }

        // Furo de pivô
        translate([0, pivo_offset_y - dedo_comp/2 - dedo_esp, dedo_esp/2])
            rotate([0,90,0])
                cylinder(r=pivo_raio, h=dedo_larg + 6, center=true);

        // Chanfros internos (alivio de peso — microgravidade)
        translate([0, dedo_comp * 0.3, dedo_comp * 0.1])
            rotate([5,0,0])
                cube([dedo_larg * 0.4, dedo_comp * 0.4, dedo_comp * 0.3], center=true);
    }
}

// ============================================================
//  TAMPA / PLACA SUPERIOR com texto gravado
// ============================================================
module tampa_logo() {
    difference() {
        cube([base_largura, base_comp, 1.5], center=true);

        // Texto gravado "D&R" (Docking & Retrieval)
        translate([-8, 5, 0])
            linear_extrude(height=1, center=true)
                text("D&R", size=7, font="Liberation Sans:style=Bold",
                     halign="center", valign="center");

        // Símbolo de satélite (círculo + cruz simplificado)
        translate([0, -10, 0]) {
            cylinder(r=4, h=1, center=true);
            cube([12, 1.5, 1], center=true);
            cube([1.5, 12, 1], center=true);
        }
    }
}

// ============================================================
//  ELO DO BRAÇO (link intermediário)
//  Peça que conecta servo à garra
// ============================================================
module elo_braco(
    comp   = 60,    // comprimento do elo
    larg   = 14,    // largura
    esp    = 8,     // espessura
    furo_r = 2.5    // raio dos furos de articulação
) {
    difference() {
        // Corpo principal arredondado
        hull() {
            translate([0, -comp/2 + larg/2, 0])
                cylinder(r=larg/2, h=esp, center=true);
            translate([0,  comp/2 - larg/2, 0])
                cylinder(r=larg/2, h=esp, center=true);
        }

        // Furos de pivô nas extremidades
        for (sy=[-1,1])
            translate([0, sy*(comp/2 - larg/2), 0])
                cylinder(r=furo_r, h=esp + 2, center=true);

        // Aliviamento central de peso (hexagonal)
        rotate([0,0,30])
            cylinder(r=larg/2 - 3, h=esp + 2, $fn=6, center=true);
    }
}


// ============================================================
//  RENDERIZAÇÃO
//  Comente/descomente o que quiser visualizar
// ============================================================

// -- Montagem completa (para render final)
montagem_completa();

// -- Apenas a base (para impressão separada)
// translate([0, 0, base_altura/2]) base_central();

// -- Apenas um dedo
// translate([60, 0, 0]) dedo();

// -- Elo do braço (peça intermediária)
// translate([0, 70, 0]) elo_braco();

// -- Vista explodida
// translate([0, 0, 0])  color(cor_base)   base_central();
// translate([0, 0, 35]) color(cor_dedo)   dedo();
// translate([0, 0, 70]) color(cor_detalhe) elo_braco();

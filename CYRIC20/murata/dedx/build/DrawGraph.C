{
    TCanvas c;
    auto h = gPad->DrawFrame(0, 0, 20, 50);
    h->GetXaxis()->SetTitle("dE Si 100 um");
    h->GetYaxis()->SetTitle("dE Si 500 um");

    gp->SetMarkerStyle(20);
    gp->SetMarkerColor(628);
    gp->SetLineColor(628);
    gp->Draw("pl");

    gd->SetMarkerStyle(21);
    gd->SetMarkerColor(625);
    gd->SetLineColor(625);
    gd->SetLineStyle(9);
    gd->Draw("pl");

    gt->SetMarkerStyle(22);
    gt->SetMarkerColor(623);
    gt->SetLineColor(623);
    gt->SetLineStyle(9);
    gt->Draw("pl");

    g3He->SetMarkerStyle(21);
    g3He->SetMarkerColor(593);
    g3He->SetLineColor(593);
    g3He->SetLineStyle(9);
    g3He->Draw("pl");

    ga->SetMarkerStyle(20);
    ga->SetMarkerColor(596);
    ga->SetLineColor(596);
    ga->Draw("pl");

    g6Li->SetMarkerStyle(21);
    g6Li->SetMarkerColor(409);
    g6Li->SetLineColor(409);
    g6Li->SetLineStyle(9);
    g6Li->Draw("pl");

    g7Li->SetMarkerStyle(20);
    g7Li->SetMarkerColor(412);
    g7Li->SetLineColor(412);
    g7Li->Draw("pl");

    g10B->SetMarkerStyle(20);
    g10B->SetMarkerColor(612);
    g10B->SetLineColor(612);
    g10B->Draw("pl");

    g12C->SetMarkerStyle(20);
    g12C->SetMarkerColor(396);
    g12C->SetLineColor(396);
    g12C->Draw("pl");

    TLegend leg(0.15, 0.55, 0.3, 0.85);
    leg.AddEntry(gp, "p", "lp");
    leg.AddEntry(gd, "d", "lp");
    leg.AddEntry(gt, "t", "lp");

    leg.AddEntry(g3He, "3He", "lp");
    leg.AddEntry(ga, "a", "lp");
    leg.AddEntry(g6Li, "6Li", "lp");
    leg.AddEntry(g7Li, "7Li", "lp");

    leg.AddEntry(g10B, "10B", "lp");
    leg.AddEntry(g12C, "12C", "lp");

    leg.Draw();
}
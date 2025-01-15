data.map(region => elt.total = elt.dut + elt.dut + elt.mes + elt.ing)

data.some((region) => region.ing < 5000);

data.sort((regionA, regionB) => regionB.mes - regionA.mes)
        .slice(0, 3));

        data.sort((regionA, regionB) => regionA.dut - regionB.dut)

data.filter((region) => region.ing < region.dut)

data.every(region => region.dut > 5000)data
    .reduce((accumulator, currentValue) => accumulator + currentValue);

data.reduce((accumulator, currentValue) => currentValue.bts > accumulator.bts ? currentValue : accumulator)

data.filter(region => region.mes > 6000)
     .map(region => elt.total = elt.dut + elt.dut + elt.mes + elt.ing)
     .reduce((accumulator, currentValue) => accumulator + currentValue);